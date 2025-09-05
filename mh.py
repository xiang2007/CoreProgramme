import requests
import time
import pandas as pd
from bs4 import BeautifulSoup

BASE_API = "https://minershaven.fandom.com/api.php"
BASE_URL = "https://minershaven.fandom.com/wiki/"
HEADERS = {"User-Agent": "MH-Scraper/1.0"}


def get_all_pages():
    """Fetch all wiki pages using the Fandom API"""
    all_pages = []
    apcontinue = None

    while True:
        params = {
            "action": "query",
            "format": "json",
            "list": "allpages",
            "aplimit": "500"
        }
        if apcontinue:
            params["apcontinue"] = apcontinue

        r = requests.get(BASE_API, params=params, headers=HEADERS)
        data = r.json()

        pages = data["query"]["allpages"]
        for p in pages:
            all_pages.append({
                "title": p["title"],
                "url": f"{BASE_URL}{p['title'].replace(' ', '_')}"
            })

        if "continue" in data:
            apcontinue = data["continue"]["apcontinue"]
            time.sleep(0.2)
        else:
            break

    return all_pages


def scrape_item_page(url):
    """Scrape details from a single item page"""
    r = requests.get(url, headers=HEADERS)
    soup = BeautifulSoup(r.text, "html.parser")

    # Check for infobox (skip if not found, means not an item page)
    infobox = soup.select_one(".portable-infobox")
    if not infobox:
        return None

    item_data = {"url": url}

    # Title
    title = soup.find("h1", {"class": "page-header__title"})
    item_data["name"] = title.get_text(strip=True) if title else "Unknown"

    # Infobox data
    info_dict = {}
    for row in infobox.select(".pi-item.pi-data"):
        label = row.select_one(".pi-data-label")
        value = row.select_one(".pi-data-value")
        if label and value:
            info_dict[label.get_text(strip=True)] = value.get_text(" ", strip=True)
    item_data["infobox"] = info_dict

    # Main description (first paragraph in main content)
    main_text = []
    for p in soup.select(".mw-parser-output > p"):
        txt = p.get_text(strip=True)
        if txt:
            main_text.append(txt)
    item_data["description"] = "\n".join(main_text[:3])  # limit intro

    # Images
    images = []
    for img in soup.select(".portable-infobox img, .mw-parser-output img"):
        src = img.get("src")
        if src and "static" not in src:
            images.append(src)
    item_data["images"] = list(set(images))

    # Subsections (like Trivia, Usage, History)
    subsections = {}
    for h2 in soup.select(".mw-parser-output > h2"):
        title = h2.get_text(" ", strip=True).replace("[edit]", "").strip()
        content = []
        sib = h2.find_next_sibling()
        while sib and sib.name not in ["h2"]:
            if sib.name == "p":
                content.append(sib.get_text(" ", strip=True))
            sib = sib.find_next_sibling()
        if content:
            subsections[title] = "\n".join(content)
    item_data["subsections"] = subsections

    return item_data


def save_to_excel(items, filename="miners_haven_items.xlsx"):
    """Save scraped items into organized Excel sheets"""
    general, stats, images, descriptions, extras = [], [], [], [], []

    for item in items:
        if not item:
            continue
        # General
        general.append({"Name": item["name"], "URL": item["url"]})

        # Stats (infobox)
        for k, v in item.get("infobox", {}).items():
            stats.append({"Name": item["name"], "Stat": k, "Value": v})

        # Images
        for img in item.get("images", []):
            images.append({"Name": item["name"], "ImageURL": img})

        # Description
        descriptions.append({"Name": item["name"], "Description": item.get("description", "")})

        # Subsections
        for k, v in item.get("subsections", {}).items():
            extras.append({"Name": item["name"], "Section": k, "Content": v})

    with pd.ExcelWriter(filename, engine="openpyxl") as writer:
        pd.DataFrame(general).to_excel(writer, sheet_name="General", index=False)
        pd.DataFrame(stats).to_excel(writer, sheet_name="Stats", index=False)
        pd.DataFrame(images).to_excel(writer, sheet_name="Images", index=False)
        pd.DataFrame(descriptions).to_excel(writer, sheet_name="Descriptions", index=False)
        pd.DataFrame(extras).to_excel(writer, sheet_name="Subsections", index=False)


def main():
    pages = get_all_pages()
    print(f"Found {len(pages)} pages in wiki")

    items = []
    for i, page in enumerate(pages):
        print(f"[{i+1}/{len(pages)}] Scraping {page['title']} ...")
        item = scrape_item_page(page["url"])
        if item:
            items.append(item)
        time.sleep(0.5)  # be nice to server

    print(f"Scraped {len(items)} items")
    save_to_excel(items)


if __name__ == "__main__":
    main()

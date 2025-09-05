import requests
from bs4 import BeautifulSoup
import pandas as pd
import time

BASE_URL = "https://minershaven.fandom.com"
WIKI_BASE = f"{BASE_URL}/wiki"

CATEGORIES = [
    "Category:Shop_Item",
    "Category:Dropper",
    "Category:Upgrader",
    "Category:Furnace",
    "Category:Utility",
    "Category:Rebirth",
    "Category:Reborn"
]

HEADERS = {
    "User-Agent": "Mozilla/5.0 (compatible; MinersHavenScraper/1.0)"
}

def get_soup(url):
    print(f"Fetching: {url}")
    res = requests.get(url, headers=HEADERS)
    res.raise_for_status()  # Raise error if bad response
    return BeautifulSoup(res.text, 'html.parser')

def get_all_pages(category_url):
    """Get all pagination URLs from a category page."""
    pages = [category_url]
    while True:
        soup = get_soup(pages[-1])
        next_page_link = soup.select_one('a.category-page__pagination-next')
        if next_page_link:
            href = next_page_link.get('href')
            if href.startswith('http'):      # full URL
                next_url = href
            else:                            # relative path
                next_url = BASE_URL + href
            if next_url not in pages:
                print("Next page URL:", next_url)  # DEBUG
                pages.append(next_url)
            else:
                break
        else:
            break
    return pages


def extract_item_links(category_page_url):
    """Extract all item links on a category page."""
    soup = get_soup(category_page_url)
    items = []
    links = soup.select('div.category-page__members div.category-page__member a.category-page__member-link')
    for a in links:
        href = a.get('href')
        name = a.text.strip()
        if href and name:
            if href.startswith('http'):       # full URL
                full_url = href
            else:                             # relative path
                full_url = BASE_URL + href
            items.append({'name': name, 'url': full_url})
    return items


def scrape_item_page(url):
    soup = get_soup(url)
    title = soup.select_one('h1.page-header__title')
    page_title = title.text.strip() if title else ''
    image_tag = soup.select_one('aside.portable-infobox figure.pi-image img')
    image_url = image_tag['src'] if image_tag else ''
    desc = ""
    content_div = soup.select_one('div.mw-parser-output')
    if content_div:
        paragraphs = content_div.find_all('p', recursive=False)
        count = 0
        for p in paragraphs:
            if p.text.strip():
                desc += p.text.strip() + " "
                count += 1
            if count >= 3:
                break
    desc = desc.strip()

    data = {'Name': page_title, 'URL': url, 'Description': desc, 'Image_URL': image_url}
    infobox = soup.select_one('aside.portable-infobox')
    if infobox:
        sections = infobox.select('section.pi-item')
        for section in sections:
            label = section.select_one('h3.pi-data-label')
            value = section.select_one('div.pi-data-value')
            if label and value:
                key = label.text.strip()
                val = value.text.strip().replace('\n', ' | ')
                data[key] = val
    else:
        print(f"No infobox found on {url}")

    return data

def scrape_category(category):
    category_url = f"{WIKI_BASE}/{category}"
    pages = get_all_pages(category_url)
    print(f"Category {category} total pages to scrape: {len(pages)}")
    all_items = []
    for page_url in pages:
        items = extract_item_links(page_url)
        print(f"Scraping {len(items)} items from {page_url}")
        for item in items:
            print(f"Scraping item: {item['name']}")
            try:
                item_data = scrape_item_page(item['url'])
                all_items.append(item_data)
                time.sleep(0.5)
            except Exception as e:
                print(f"Error scraping {item['name']}: {e}")
    return all_items

def main():
    writer = pd.ExcelWriter('miners_haven_full_items_detailed.xlsx', engine='openpyxl')
    for category in CATEGORIES:
        print(f"Starting category: {category}")
        data = scrape_category(category)
        if data:
            df = pd.DataFrame(data)
            df.columns = [col.replace('\n', ' ').replace('\r',' ').strip() for col in df.columns]
            cols = list(df.columns)
            if 'Name' in cols:
                cols.remove('Name')
                cols = ['Name'] + sorted(cols)
            df = df[cols]
            sheet_name = category.replace('Category:', '')[:31]
            df.to_excel(writer, index=False, sheet_name=sheet_name)
    print("Scraping finished and saved.")

if __name__ == "__main__":
    main()

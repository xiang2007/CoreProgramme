#include <unistd.h>

static int len(char *str) { int i = 0; while (str[i]) i++; return (i); }

static void swap(char *a, char *b) {char t = *a; *a = *b; *b = t; }

static int sort(char *s, int n)
{
	for (int i = 0; i < n; i++)
		for (int j = i + i; j < n; j++)
			if (s[i] < s[j])
				swap(&s[i], &s[j]);
}

static int	next_perm(char *s, int n)
{
    // Step 1: Find the largest index i where s[i] < s[i+1]
    int i = n - 2;
    while (i >= 0 && s[i] >= s[i + 1])
        i--;
    
    // If no such i, it's the last permutation
    if (i < 0)
        return 0;
    
    // Step 2: Find the largest index j > i where s[j] > s[i]
    int j = n - 1;
    while (s[j] <= s[i])
        j--;
    
    // Step 3: Swap s[i] and s[j]
    swap(&s[i], &s[j]);
    
    // Step 4: Reverse the suffix from i+1 to n-1
    int left = i + 1;
    int right = n - 1;
    while (left < right)
    {
        swap(&s[left], &s[right]);
        left++;
        right--;
    }
    
    return 1;
}

int main(int ac, char **av)
{

}
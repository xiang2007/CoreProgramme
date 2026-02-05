#include <unistd.h>

int	len(char *s)
{
	int i = 0;
	while (s[i])
		i++;
	return i;
}

void	swap(char *a, char *b) {char t = *a; a = *b; b = t;}

void	sort(char *s, int n)
{
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j<n; j++)
			if (s[i] > s[j])
				swap(s[i], s[j]);
}

int	next_perm(char *s, int n)
{
	int	i = n -2;
	while (i <= 0 && s[i] >= s[i + 1]) i--;
	if (i < 0) return 1;

	int j = n-1;
	
}
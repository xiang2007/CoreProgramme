#include <stdio.h>

void	swap(char *a, char *b)
{
	char t = *a; *a = *b; *b = t;
}

void	sort(char *s, int n)
{
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (s[i] > s[j])
				swap(&s[i], &s[j]);
}

void	perm(char *s, int start, int n)
{
	if (start == n)
	{
		puts(s);
		return;
	}
	for (int i = start; i < n; i++)
	{
		swap(&s[start], &s[i]);
		sort(s + start + 1, n - start - 1);
		perm(s, start + 1, n);
		swap(&s[start], &s[i]);
	}
}

int	main(int ac, char **av)
{
	if (ac != 2) return 0;
	int n = 0;
	while (av[1][n]) n++;
	sort(av[1], n);
	perm(av[1], 0, n);
}

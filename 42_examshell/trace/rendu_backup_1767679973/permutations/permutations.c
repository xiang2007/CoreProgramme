#include <unistd.h>

int	len(char *str) {int i = 0; while (str[i]) i++; return i;}

void	swap(char *a, char *b) { char t = *a; *a = *b; *b = t ;}

void	_sort(char *s, int n)
{
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
				if (s[i] > s[j])
					swap(&s[i], &s[j]);
}

int	next_perm(char *s, int n)
{
	int i = n - 2;
	while (i >= 0 && s[i] >= s[i + 1]) i--;
	if (i < 0) return 0;
	int j = n - 1;
	while (s[j] <= s[i]) j--;
	swap(&s[i], &s[j]);
	for (int l = i + 1, r = n - 1; l < r; l++, r--) swap(&s[l], &s[r]);
	return 1;
}

int	main(int ac, char **av)
{
	if (ac != 2)
		return (1);
	int n = len(av[1]);
	_sort(av[1], n);
	do {
		write(1, av[1], n);
		write(1, "\n", 1);
	} while (next_perm(av[1], n));
}

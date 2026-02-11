#include <unistd.h>

int len (char *s)
{
	int i = 0;
	while (s[i])
		i++;
	return (i);
}

void	swap(char *a, char *b) {char t = *a; *a = *b; *b = t;}

void	sort(char *s, int n)
{
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; i++)
			if (s[i] > s[j])
				swap(&s[i], &s[j]);
}

int	next_perm(char *s, int n)
{
	int i = n - 2;
	int j, k, l;
	while (i >= 0 && s[i] >= s[i + 1])
		i--;
	if (i < 0)
		return 0;
	j = n - 1;
	while (s[j] <= s[i])
		j--;
	swap(&s[i], &s[j]);
	k = i + 1;
	l = n - 1;
	while (k < l)
	{
		swap(&s[k], &s[l]);
		k++;
		l--;
	}
	return 1;
}

int	main(int ac, char **av)
{
	int n;

	if (ac != 2)
		return 1;
	n = len(av[1]);
	sort(av[1], n);
	do {
		write(1, av[1], n);
		write(1, "\n", 1);
	} while (next_perm(av[1], n));
}
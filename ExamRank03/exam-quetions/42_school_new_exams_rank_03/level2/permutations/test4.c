#include <unistd.h>

static int len(char *s)
{
	int i = 0;
	while (s[i]) i++;
	return i;
}

static void swap(char *a, char *b)
{
	char t = *a; *a = *b; *b = t;
}

static void sort(char  *s, int n)
{
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			if (s[i] > s[j])
				swap(&s[i], &s[j]);
}

static int next_perm(char *s, int n)
{
	int i = n - 2;
	int j, l, r;
	while (i >= 0 && s[i] >= s[i + 1])
		i--;
	if (i < 0)
		return 0;
	j = n - 1;
	while (s[i] >= s[j])
		j--;
	swap(&s[i], &s[j]);
	l = i + 1;
	r = n - 1;
	while (l < r)
	{
		swap(&s[l], &s[r]);
		l++;
		r--;
	}
	return 1;
}

int main(int ac, char **av)
{
	if (ac != 2) return 1;

	int n = len(av[1]);
	sort(av[1], n);

	while (next_perm(av[1], n))
	{
		write(1, av[1], n);
		write(1, "\n", 1);
	}
}
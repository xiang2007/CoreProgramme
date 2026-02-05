#include <unistd.h>

static int len(char *s) {int i = 0; while(s[i]) i++; return (i);}

static void swap(char *a, char *b) { char t = *a; a = *b; b = t; }

static void sort(char *s, int n)
{
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			if (s[i] > s[j])
				swap(&s[i], &s[j]);
}

static int next_perm(char *s, int n)
{
	int pivot = n - 2;
	while (pivot >= 0 && s[pivot] >= s[pivot + 1])
		pivot--;
	
	int ss = n - 1;
	while (s[ss] <= s[pivot])
		ss--;
	ft_swap(&s[pivot], &s[ss]);

	int left = pi
}

int main(int ac, char **av)
{
	if (ac != 2) return 1;

	int n = len(av[1]);
	sort(av[1], n);

	do {
		write(1, av[1], n);
		write(1, "\n", 1);
	} while (next_perm(av[1], n));
}
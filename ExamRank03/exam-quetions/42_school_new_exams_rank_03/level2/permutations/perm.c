#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	perm_size;
int	total_perm;
char	**list;
char	*ori;

void	ft_sort(char *a, int l, int n);

int	ft_strlen(char *str)
{
	if (!str)
		return (0);
	int	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_factorial(int n)
{
	if (n <= 1)
		return 1;
	else
		return (n * ft_factorial(n - 1));
}

void	swap(char *a, char *b) {char t = *a; *a = *b; *b = t; }

void	permute(char *a, int i, int n)
{
	if (i == (n - 1)) printf("%s\n", a);
	else
	{
		for (int j = i; j < n; j++)
		{
			swap(&a[i], &a[j]);
			ft_sort(a, i + 1, n);
			permute(a, i + 1, n);
			ft_sort(a, i + 1, n);
			swap(&a[i], &a[j]);
		}
	}
}

void	ft_sort(char *a, int l, int n)
{
	for (int i = l; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (a[i] > a[j])
				swap(&a[i], &a[j]);
}

void	ft_strcpy(char *src, char *dest)
{
	int i;
	for (i = 0; src[i]; i++)
		dest[i] = src[i];
	dest[i] = '\0';
}

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		perm_size = ft_strlen(av[1]);
		total_perm = ft_factorial(perm_size);
		char	*res = malloc(sizeof(char) * (total_perm + 1));
		ft_sort(av[1], 0, ft_strlen(av[1]));
		ft_strcpy(av[1], res);
		permute(res, 0, perm_size);
		free(res);
	}
	else
		return (0);
}
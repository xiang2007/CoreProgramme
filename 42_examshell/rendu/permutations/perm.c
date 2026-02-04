#include <unistd.h>

char	**res;
int		n;

int	len (char *str) {int i = 0; while(str[i]) {i++;} return i;}

void	swap(char *x, char *y) {char t = *x; *x = *y; *y = t;}

void	sort(char *str, int n)
{
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++) {
			if (str[i] > str[j])
				swap(&str[i], &str[j]);
		}
}



int	main(int ac, char **av)
{
	if (ac != 2) return 0;
	int n = 0;
	while (av[1][n]) n++;
	sort(av[1], n);
	do {
		
	}
}
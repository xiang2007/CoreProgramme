#include <stdio.h>

double n_times(double nbr, int n)
{
	while (n)
	{
		nbr /= 10;
		n--;
	}
	return (nbr);
}

int	main(int ac, char **av)
{
	double res;
	double temp;
	int i;
	int	n;
	int negative;

	res = 0;
	temp = 0;
	i = 2;
	n = 1;
	negative = 1;
	while(av[1][i])
	{
		if (av[1][0] == '-')
			negative = -1;
		if (av[1][i] >= '0' && av[1][i] <= '9')
		{
			temp = av[1][i] - '0';
			temp = n_times(temp, n);
			res += temp;
			n++;
		}
		i++;
	}
	return (res * negative);
}

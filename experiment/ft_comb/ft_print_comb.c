#include <unistd.h>

void	ft_putnbr(int i)
{
	char nbr;

	nbr = i + '0';
	write(1, &nbr, 1);
}

void	special(void)
{
	ft_putnbr(7);
	ft_putnbr(8);
	ft_putnbr(9);
}

void	print_comb(void)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	while (i < 7)
	{
		j = i + 1;
		while (j < 8)
		{
			k = j + 1;
			while (k < 9)
			{
				ft_putnbr(i);
				ft_putnbr(j);
				ft_putnbr(k);
				write(1, ", ", 2);
				k++;
			}
			j++;
		}
		i++;
	}
	special();
	write(1, "\n", 1);
}

int	main()
{
	print_comb();
	return (0);
}
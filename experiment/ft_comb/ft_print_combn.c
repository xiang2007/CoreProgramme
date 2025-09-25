#include <unistd.h>

void	ft_putnbr(int i)
{
	char temp;
	temp = i + '0';
	write(1, &temp, 1);
}

void	ft_print_combn(int n)
{
	int	i;
	int	j;
	int	temp;
	int	size;

	size = n;
	temp = n - size;
	while (n--)
	{
		while (temp < 9)
		{
			ft_putnbr(temp);
			temp++;
		}
	}
	return ;
}

int	main(void)
{
	ft_print_combn(3);
	return (0);
}
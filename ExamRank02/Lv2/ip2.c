/*Write a function that determines if a given number is a power of 2.

This function returns 1 if the given number is a power of 2, otherwise it returns 0.

Your function must be declared as follows:

int	    is_power_of_2(unsigned int n);*/

int	is_power_of_2(unsigned int n)
{
	unsigned int	nbr;

	nbr = 2;
	while (nbr <= n)
	{
		if (n == nbr)
			return (1);
		nbr *= 2;
	}
	return (0);
}

#include <stdio.h>

int	main()
{
	printf("%d\n", is_power_of_2(65536));
	return (0);
}
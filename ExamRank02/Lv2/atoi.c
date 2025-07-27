/*Write a function that converts the string argument str to an integer (type int)
and returns it.

It works much like the standard atoi(const char *str) function, see the man.

Your function must be declared as follows:

int	ft_atoi(const char *str);*/

#include <stdio.h> //For testing only

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	nbr;

	i = 0;
	sign = 1;
	nbr = 0;
	if (!str)
		return (0);
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i])
	{
		if (str[i] == '-' || str[i] == '+')
			sign *= 0;
		nbr *= 10;
		nbr += str[i] - '0';
		i++;
	}
	return (nbr * sign);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		int	nbr;

		nbr = ft_atoi(argv[1]);
		printf("%d",nbr);
	}
	printf("\n");
	return (0);
}
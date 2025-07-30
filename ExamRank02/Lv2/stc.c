/*Write a program that takes a single string in snake_case format
and converts it into a string in lowerCamelCase format.

A snake_case string is a string where each word is in lower case, separated by
an underscore "_".

A lowerCamelCase string is a string where each word begins with a capital letter
except for the first one.*/

#include <unistd.h>

char	*makeup(char *str);

int	main(int ac, char **av)
{
	int	i;
	char	*str;

	i = 0;
	if (ac == 2)
	{
		i = 0;
		while (av[1][i])
		{
			if (av[1][i] == 95)
				
		}
	}
	write(1, "\n", 1);
	return (0);
}

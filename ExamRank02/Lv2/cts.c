/*Write a program that takes a single string in lowerCamelCase format
and converts it into a string in snake_case format.

A lowerCamelCase string is a string where each word begins with a capital letter
except for the first one.

A snake_case string is a string where each word is in lower case, separated by
an underscore "_".*/

#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc == 2)
	{
		while (argv[1][i])
		{
			if (argv[1][i] >= 97 && argv[1][i] <= 122)
				write(1, &argv[1][i], 1);
			if (argv[1][i + 1] >= 65 && argv[1][i + 1] <= 90)
			{
				write(1, "_", 1);
				argv[1][i + 1] += 32;
			}
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
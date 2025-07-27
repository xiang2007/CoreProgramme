/*Write a program that takes a string and displays it, replacing each of its
letters by the letter 13 spaces ahead in alphabetical order.

'z' becomes 'm' and 'Z' becomes 'M'. Case remains unaffected.

The output will be followed by a newline.

If the number of arguments is not 1, the program displays a newline.*/

#include <unistd.h>

int		isletter(char c);
void	putschar(char c);

int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	while (argv[1][i])
	{
		if (argv[1][i] == 'z' || argv[1][i] == 'Z')
		{
			if (argv[1][i] == 'z')
				write(1, "m", 1);
			else if (argv[1][i] == 'Z')
				write(1, "M", 1);
			i++;
		}
		putschar(argv[1][i]);
		i++;
	}
	write(1, "\n", 1);
	return (0);
}

int	isletter(char c)
{
	if ((c >= 65 && c <= 77) || (c >= 97 && c <= 109))
		return (1);
	if ((c >= 79 && c <= 90) || (c >= 110 && c <= 122))
		return (2);
	else
		return (0);
}

void	putschar(char c)
{
	if (!isletter(c))
		write(1, &c, 1);
	else if (isletter(c) == 1)
	{
		c += 13;
		write(1, &c, 1);
	}
	else if (isletter(c) == 2)
	{
		c -= 13;
		write(1, &c, 1);
	}
}

/*Write a program that takes a string, and displays the string in reverse
followed by a newline.

If the number of parameters is not 1, the program displays a newline.*/

#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc != 2 || !(argv[1][0]))
	{
		write(1, "\n", 1);
		return (0);
	}
	while (argv[1][i])
		i++;
	while (i >= 0)
		write(1, &argv[1][i--], 1);
	write(1, "\n", 1);
	return (0);
}
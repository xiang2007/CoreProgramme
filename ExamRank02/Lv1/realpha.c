/*Write a program called repeat_alpha that takes a string and display it
repeating each alphabetical character as many times as its alphabetical index,
followed by a newline.

'a' becomes 'a', 'b' becomes 'bb', 'e' becomes 'eeeee', etc...

Case remains unchanged.

If the number of arguments is not 1, just display a newline.*/

#include <unistd.h>

int	calpos(char c)
{
	int	i;
	if (c >= 65 && c <= 90)
		i = (c - 64);
	else
		i = (c - 96);
	return (i);
}

int	main(int argc, char **argv)
{
	int	i;
	int	re;

	i = 0;
	if (argc != 2 || !(argv[1][0]))
	{
		write(1, "\n", 1);
		return (0);
	}
	if (!argv[1][i])
		return (0);
	while (argv[i][1] == 32)
		i++;
	while (argv[1][i])
	{
		if (!(argv[1][i] >= 65 && argv[1][i] <= 90) 
			|| (argv[1][i] >= 96 && argv[1][i] <= 122))
			return (0);
		re = calpos(argv[1][i]);
		while (re != 0)
		{
			write(1, &argv[1][i], 1);
			re--;
		}
		i++;
	}
	write(1, "\n", 1);
	return (0);
}
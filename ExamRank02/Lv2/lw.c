/*Write a program that takes a string and displays its last word followed by a \n.

A word is a section of string delimited by spaces/tabs or by the start/end of
the string.

If the number of parameters is not 1, or there are no words, display a newline.*/

//i quit


#include <unistd.h>

int	main(int ac, char **av)
{
	int	len;


	len = 0;
	if (ac == 2)
	{
		while (av[1][len]) //move to the last letter
			len++;
		while (av[1][len] == ' ')
			len--;
		while (av[1][len] != ' ' && len > 0)
			len--;
		while (av[1][len] && av[1][len] != ' ')
			write(1, &av[1][len++], 1);
		write(1, "\n", 1);
		return (0);
	}
}

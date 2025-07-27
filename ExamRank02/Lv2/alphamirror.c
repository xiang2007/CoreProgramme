/*Write a program called alpha_mirror that takes a string and displays this string
after replacing each alphabetical character by the opposite alphabetical
character, followed by a newline.

'a' becomes 'z', 'Z' becomes 'A'
'd' becomes 'w', 'M' becomes 'N'

and so on.

Case is not changed.

If the number of arguments is not 1, display only a newline.*/

#include <unistd.h>

int	main(int argc, char **argv)
{
	char	*strup = {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
	char	*strdown = {"abcdefghijklmnopqrstuvwxyz"};
	int	i;

	i = 0;
	if (argc == 2)
	{
		while (argv[1][i])
		{
			if (argv[1][i] >= 65 && argv[1][i] <= 90)
				write(1, &strup[90 - (argv[1][i])], 1);
			else if (argv[1][i] >= 97 && argv[1][i] <= 122)
				write(1, &strdown[122 - (argv[1][i])], 1);
			else
				write(1, &argv[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
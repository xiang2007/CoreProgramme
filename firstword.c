#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc == 1)
		return (0);
	while (argv[1][i] == 32)
		i++;
	while (argv[1][i])
	{
		if (argv[1][i] != 32)
			write(1, &argv[1][i], 1);
		else if (argv[1][i] == 32)
			break;
		i++;
	}
	write(1, "\n", 1);
	return (0);
}
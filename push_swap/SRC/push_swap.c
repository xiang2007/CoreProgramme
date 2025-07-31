#include "push_swap.h"

int	print(char *str);
static int	check_valid(char **str, int len);

int	main(int ac, char **av)
{
	if (ac >= 2)
	{
		print(av[1]);
	}
	return (0);
}


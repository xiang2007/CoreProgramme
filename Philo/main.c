#include "philos.h"


int	main(int ac, char **av)
{
	t_args ag;

	if (asign(ac, av, &ag) > 0)
		return (1);
	return (0);
}
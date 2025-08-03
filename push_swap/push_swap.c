#include "push_swap.h"

#include <stdio.h>
int	main(int ac, char **av)
{
	if (ac > 2 && isvalid(av))
	{
		printf("Is valid? %d\n",isvalid(av));
	}
	return (0);
}

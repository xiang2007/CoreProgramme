#include "includes/fol.h"

int	main(int ac, char **av)
{
	int	limit;
	d	z;
	d res;
	d	c;

	if (ac == 1)
	{
		limit = 1000;
		z = 0;
		c = 0.04;
		while ((limit--) && (z < 2))
		{
			res = (z * z) + c;
			printf("number is: %f\n", res);
			z = res;
		}
	}
	return (0);
}
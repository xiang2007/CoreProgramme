#include "mallib.h"

int	main(int ac, char **av)
{
	int	*arr;
	int	i;

	i = 1;
	if (ac > 1)
	{
		arr = (int *)malloc(sizeof(int) * (ac - 1));
		while (av[i])
		{
			arr[i - 1] = atoi(av[i]);
			printf("number is %d\n", arr[i - 1]);
			i++;
		}
		free(arr);
	}
	return (0);
}
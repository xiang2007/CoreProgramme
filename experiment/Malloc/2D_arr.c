#include "mallib.h"

int	main(int ac, char **av)
{
	int	i;
	int	j;
	int	**arr;

	if (ac > 1)
	{
		i = 0;
		arr = (int **)malloc(sizeof(int *) * (ac - 1));
		while(av[i + 1])
		{
			arr[i] = (int *)malloc(sizeof(int));
			*arr[i] = atoi(av[i + 1]);
			printf("Number is %d\n", arr[i][0]);
			i++; 
		}
		j = 0;
		while(j < i)
		{
			free(arr[j]);
			j++;
		}
		free(arr);
		return (0);
	}
}
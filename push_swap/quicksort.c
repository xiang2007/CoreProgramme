#include "push_swap.h"

/*void	quick_sort(int *arr)
{

}*/

int	*bsort(int *arr, int size)
{
	int i;
	int j;
	int temp;

	i = 0;
	j = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
	return (arr);
}

int find_pivot(int *arr, int size)
{
	if (size % 2 != 0)
		return (arr[size / 2]);
	return ((arr[(size - 1) / 2] + arr[size / 2]) / 2);
}

int	*partition(int *arr, int size, int pivot)
{
	int	i;
	int j;
	int	temp;

	if (!arr || size < 0)
		return (0);
	i = 0;
	j = size - 1;
	while (1)
	{
		while (arr[i] < pivot)
			i++;
		while (arr[j] > pivot)
			j--;
		if (i < j)
		{
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
		else
			return (arr);
	}
}

int *asign_arr(int ac, char **av)
{
	int *arr;
	int i;
	int j;

	i = 0;
	j = 1;
	arr = (int *)malloc(sizeof(int) * (ac - 1));
	if (!arr)
		return (0);
	while (i < ac - 1)
	{
		arr[i] = atoi(av[j]);
		i++;
		j++;
	}
	return (arr);
}
int	main(int ac, char **av)
{
	int *arr;
	int *temp;
	int	i;

	i = 0;
	if (ac > 2)
	{
		arr = asign_arr(ac, av);
		temp = asign_arr(ac, av);
		temp = bsort(temp, ac - 1);
		arr = partition(arr, (ac - 1), find_pivot(temp, ac - 1));
		i = 0;
		while (i < ac - 1)
		{
			printf("pos %d value is %d\n", i, arr[i]);
			i++;
		}
	}
	return (0);
}

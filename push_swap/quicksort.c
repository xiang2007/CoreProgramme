#include "push_swap.h"

int	qs_partition(int *arr, int first, int last);

void	sort(int *arr, int first, int last)
{
	int i;

	if (first < last)
	{
		i = qs_partition(arr, first, last);
		sort(arr, first, i);
		sort(arr, i + 1, last);
	}
}

int	qs_partition(int *arr, int first, int last)
{
	int pivot;
	int	i;
	int j;
	int	temp;

	i = first;
	j = last - 1;
	pivot = arr[(first + last) / 2];
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
			return (j);
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

int	quicksort(int ac, char **av)
{
	int *arr;

	arr = asign_arr(ac, av);
	sort(arr, 0, (ac - 1));
	return (arr[0 + (ac - 1) / 2]);
}

#include "sudoku.h"

int main(int ac, char **av)
{
	t_var 	var;
	int		iter;
	int		**arr;

	if (ac == 2)
	{
		var.i = 0;
		arr = (int **)malloc(sizeof(int *) * (ac - 1) * 9);
		iter = 1;
		while (av[iter])
		{
			var.j = 0;
			arr[var.i] = (int *)malloc(sizeof(int) * 9);
			while(var.j < 9)
			{
				arr[var.i][var.j] = atoi(av[iter]);
				printf("Number is %d\n", arr[var.i][var.j]);
				iter++;
			var.j++;
			}
		var.i++;
	}
	var.i = 0;
	while (var.i < 9)
	{
		var.j = 0;
		while (var.j < 9)
		{
			printf("arr %d = %d\n", var.i, arr[var.i][var.j]);
			var.j++;
		}
		var.i++;
	}
	fint(arr, ac - 1);
	return (0);
	}
}

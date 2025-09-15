#include "sudoku.h"

int	**asign_block(char **av, int **arr)
{
	t_var	var;
	int		iter;

	var.i = 0;
	iter = 1;
	while (av[iter])
	{
		var.j = 0;
		arr[var.i] = (int *)malloc(sizeof(int *) * 10);
		while(var.j < 9)
		{
			arr[var.i][var.j] = atoi(av[iter]);
			printf("Number is %d\n", arr[var.i][var.j]);
			iter++;
			var.j++;
		}
		var.i++;
	}
	return (arr);
}

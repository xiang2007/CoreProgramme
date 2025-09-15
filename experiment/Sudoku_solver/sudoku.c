#include "sudoku.h"

int main(int ac, char **av)
{
	t_var 	var;
	int		**block;

	if (ac == 2)
	{
		var.i = 0;
		block = (int **)malloc(sizeof(int **) * 9 * 9);
		block = asign_block(av, block);
		while (var.i < 9)
		{
			var.j = 0;
			while (var.j < 9)
			{
				printf("block %d = %d\n", var.i, block[var.i][var.j]);
				var.j++;
			}
			var.i++;
		}
		fint(block);
		return (0);
	}
}

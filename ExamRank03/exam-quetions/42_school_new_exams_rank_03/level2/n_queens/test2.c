#include <stdio.h>
#include <stdlib.h>

int	*board;
int	board_size;

void	print_sol()
{
	for (int i = 0; i < board_size; i++)
	{
		fprintf(stdout, "%d", board[i]);
		if (i < board_size - 1)
			fprintf(stdout, " ");
	}
	fprintf(stdout, "\n");
}

int	ft_abs(int n) {if (n < 0) return (-n); else return n;}

int	is_safe(int row, int col)
{
	for (int i = 0; i < col; i++)
	{
		if (board[i] == row)
			return (0);
		else if (ft_abs(board[i] - row) == ft_abs(i - col))
			return (0);
	}
	return (1);
}

void	solve(int col)
{
	if (col == board_size)
	{
		print_sol();
		return ;
	}
	for (int i = 0; i < board_size; i++)
	{
		if (is_safe(i, col))
		{
			board[col] = i;
			solve(col + 1);
		}
	}
}

int	main(int ac, char **av)
{
	if (ac != 2)
		return (1);
	board_size = atoi(av[1]);
	board = malloc(sizeof(int) * board_size);
	solve(0);
	free(board);
	return (0);
	
}
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	*board;
int	board_size;

void	print_board()
{
	int	i;
	for (i = 0; i < board_size; i++)
	{
		fprintf(stdout, "%d", board[i]);
		if (i < board_size - 1)
			fprintf(stdout, " ");
	}
	fprintf(stdout, "\n");
}

int _abs(int n){ if (n < 0) return (-n); else return (n); }

int	is_safe(int row, int col)
{
	for (int i = 0; i < col; i++) {
		if (board[i] == row)
			return 0;
		if ((_abs(board[i] - row)) == _abs(i - col))
			return 0;
	}
	return 1;
}

void	solve(int col)
{
	if (col == board_size)
	{
		print_board();
		return ;
	}
	for (int row = 0; row < board_size; row++)
	{
		if (is_safe(row, col))
		{
			board[col] = row;
			solve(col + 1);
		}
	}
}

int	main(int ac, char **av)
{
	if (ac != 2)
		return 0;
	int n = atoi(av[1]);
	board_size = n;
	board = malloc(sizeof(int) * board_size);
	solve(0);
	free(board);
	return 0;
}
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int	*board;
int	board_size;

void	print_solution()
{
	int	i;
	for (i = 0; i < board_size; i++)
	{
		if (i > 0)
			fprintf(stdout, " ");
		fprintf(stdout, "%d", board[i]);
	}
	fprintf(stdout, "\n");
}

int	ft_abs(int n) { if (n < 0) return (-n); else return (n); }

int	is_safe(int row, int col)
{
	for (int i=0; i<col; i++)
	{
		if (board[i] == row)
			return 0;
		if (ft_abs(board[i] - row) == ft_abs(i - col))
			return 0;
	}
	return 1;
}

void	solve(int col)
{
	if (col == board_size)
	{
		print_solution();
		return ;
	}
	for(int row=0; row < board_size; row++)
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
		return (write(1, "\n", 1), 1);
	int n = atoi(av[1]);
	if (n <= 3)
		return (write(1, "\n", 1), 1);
	board_size = n;
	board = malloc(sizeof(int) * board_size);
	solve(0);
	free(board);
	return 0;
}

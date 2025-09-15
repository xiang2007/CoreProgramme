#ifndef SUDOKU_H
# define SUDOKU_H

# include <stdio.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_var
{
	int i;
	int j;
}				t_var;

char	**ft_split(char const *s, char c);
void	*fall(char **src);
int		**asign_block(char **av, int **arr);
void	*fint(int **arr);

#endif
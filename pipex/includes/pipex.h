#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/wait.h>
# include <fcntl.h>
# include "libft.h"

int		check_file(char *filename);
char	*getpath(char *cmd, char **env);
void	error(void);
void	child_ps(int *fd, char **av, char **env);
void	parent_ps(int *fd, char **av, char **env);
void	execute(char *av, char **env);

#endif

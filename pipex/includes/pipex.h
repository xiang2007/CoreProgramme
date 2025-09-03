#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/wait.h>
# include <fcntl.h>
# include "libft.h"

char	*getpath(char *cmd, char **env);
void	error(int value);
void	child_ps(int *fd, char **av, char **env);
void	parent_ps(int *fd, char **av, char **env);
void	execute(char *av, char **env);
void	free_all(char **dptr);
int		check_path(char *path);
void	check_cmd(char *cmd);

#endif

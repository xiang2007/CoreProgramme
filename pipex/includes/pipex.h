#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/wait.h>
# include "ft_printf.h"
# include "libft.h"

int		check_file(char *filename);
char	*getpath(char *cmd, char **env);
void	error(void);

#endif

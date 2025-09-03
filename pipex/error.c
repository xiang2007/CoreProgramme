#include "pipex.h"

void	error(int val)
{
	if (val > 1)
	{
		perror("Error");
		exit(127);
	}
	perror("Error");
		exit(EXIT_FAILURE);
}

void	check_cmd(char *cmd)
{
	if (ft_strnstr(cmd, "./", 4) != 0)
	{
		ft_putstr_fd("pipex: command not found: ", 2);
		ft_putendl_fd(cmd, 2);
		exit (0);
	}
	return ;
}
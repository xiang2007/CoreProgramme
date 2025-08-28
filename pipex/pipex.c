#include "pipex.h"
#include <stdio.h>

int main(int ac, char **av, char **env)
{
	pid_t	pid;
	int		fd[2];

	if (ac == 5)
	{
		if (pipe(fd) == -1)
			error ();
		pid = fork();
		if (pid == -1)
			error ();
		if (pid == 1)
			child_ps(fd, av, env);
		waitpid(pid, NULL, 0);
		parent_ps(fd, av, env);	
	}
	else
	{
		ft_putstr_fd("Error: Bad arguments\n", 2);
		ft_putstr_fd("Ex: ./pipex <infile> <cmd1> <cmd2> <outfile>\n", 2);
	}
	return (0);
}

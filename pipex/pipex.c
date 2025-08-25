#include "pipex.h"
#include <stdio.h>

int main(int ac, char **av, char **env)
{
	pid_t	pid;
	int		fd[2];

	if (argc == 5)
	{
		if (pipe(fd) == -1)
			error ();
		pid = fork();
		if (pid == -1)
			error ();
		if (pid == 1)
			child_ps(fd, av, env);
		
	}
}
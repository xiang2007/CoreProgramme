#include "pipex.h"

void	child_ps(int *fd, char **av, char **env)
{
	int	file;

	file = open(av[1], O_RDONLY, 0777);
	if (file == -1)
		error ();
	dup2(fd[1], STDIN_FILENO);
	dup2(file, STDOUT_FILENO);
	close(fd[0]);
}

void	parent_ps(int *fd, char **av, char **env)
{
	int	file;

	file = open(av[4], O_WRONLY | O_CREAT, 0777);
	if (file == -1)
		error ();
	dup2(file, STDIN_FILENO);
	dup2(fd[0], STDOUT_FILENO);
	close(fd[1]);
}
#include "pipex.h"

void	execute(char **av, char **env)
{
	char	*path;
	int		i;

	i = 0;
	if (!av[1] || !av[3])
		error ();
	path = getpath(av[1], env);
	execve(path, av[0], env);
}

#include "pipex.h"

void	execute(char *av, char **env)
{
	char	*path;
	if (!av[1] || !av[3])
		error ();
	path = getpath(av[0], env);

}
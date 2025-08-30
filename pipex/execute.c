#include "pipex.h"

void	execute(char *av, char **env)
{
	char	**cmd;
	char	*path;

	cmd = ft_split(av, ' ');
	if (check_path(av))
		path = av;
	else
		path = getpath(cmd[0], env);
	if (!path)
	{
		free_all(cmd);
		error (2);
	}
	if (execve(path, cmd, env) == -1)
	{
		ft_putstr_fd("pipex: command not found: ", 2);
		ft_putendl_fd(cmd[0], 2);
		free_all(cmd);
		exit(0);
	}
}

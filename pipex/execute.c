#include "pipex.h"

void	execute(char *av, char **env)
{
	char	**cmd;
	char	*path;
	int		i;

	i = 0;
	cmd = ft_split(av, ' ');
	path = getpath(cmd[0], env);
	if (!path)
	{
		while (cmd[i])
		{
			free(cmd[i]);
			i++;
		}
		free(cmd);
		error ();
	}
	if (execve(path, cmd, env) == -1)
		error ();
}

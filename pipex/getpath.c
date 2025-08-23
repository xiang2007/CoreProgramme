#include "pipex.h"

char	*getpath(char *cmd, char **env)
{
	char	**paths;
	char	*path;
	char	*half_path;
	int		i;

	i = 0;
	(void)cmd;
	paths = ft_split(env[i] + 5, ':');
	while (paths[i])
	{
		half_path = ft_strjoin(paths[i], "/");
		path = ft_strjoin(half_path, cmd);
		free(half_path);
		if (access(path, F_OK) == 0)
			return (path);
		free(path);
		i++;
	}
	i = -1;
	while (paths[i++])
		free(paths[i]);
	free (paths);
	return (0);
}

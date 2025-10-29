/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshou-xi <wshou-xi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 19:39:35 by wshou-xi          #+#    #+#             */
/*   Updated: 2025/10/28 17:14:50 by wshou-xi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/Pipex.h"

int	i_open_file(char *av, int flag)
{
	int	fd;

	if (!av)
		exit (1);
	if (flag == 0)
		fd = open(av, O_RDONLY, 0777);
	if (flag == 1)
		fd = open(av, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fd == -1)
		exit (1);
	return (fd);
}

void	free_all(char **dptr)
{
	int	i;

	if (!dptr)
		return ;
	i = 0;
	while (dptr[i])
	{
		free(dptr[i]);
		i++;
	}
	free(dptr);
}

char	*ft_getpath(char *cmd, char **env)
{
	char	**paths;
	char	*half_path;
	char	*path;
	int		i;

	i = 0;
	while (ft_strnstr(env[i], "PATH", 4) == 0)
		i++;
	paths = ft_split(env[i] + 5, ':');
	i = 0;
	while (paths[i])
	{
		half_path = ft_strjoin(paths[i], "/");
		path = ft_strjoin(half_path, cmd);
		free(half_path);
		if (access(path, F_OK | X_OK) == 0)
		{
			free_all(paths);
			return (path);
		}
		free(path);
		i++;
	}
	free_all(paths);
	return (0);
}

char	*check_slash(char *cmd)
{
	if (!cmd || !*cmd)
		return (NULL);
	if (ft_strchr(cmd, '/'))
	{
		if (access(cmd, F_OK | X_OK))
			return (ft_strdup(cmd));
		return (NULL);
	}
	return (NULL);
}

void	exec(char *cmd, char **env)
{
	char	*path;
	char	**paths;

	paths = ft_split(cmd, ' ');
	if (!paths || !*paths)
	{
		free_all(paths);
		exit(127);
	}
	path = ft_getpath(paths[0], env);
	if (!path)
	{
		ft_putstr_fd("Error: Command not found: ", 2);
		ft_putendl_fd(paths[0], 2);
		free_all(paths);
		exit(127);
	}
	if (execve(path, paths, env) == -1)
	{
		perror("execve");
		free_all(paths);
		free(path);
		exit (127);
	}
}

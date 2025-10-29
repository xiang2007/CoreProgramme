/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshou-xi <wshou-xi@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 18:53:10 by wshou-xi          #+#    #+#             */
/*   Updated: 2025/10/29 23:27:16 by wshou-xi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		status;
pid_t	pid;

char	*ft_getenv(char **env)
{
	int		i;
	char	*env_path;

	i = 0;
	env_path = NULL;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
		{
			env_path = ft_strdup(env[i] + 5);
			break ;
		}
		i++;
	}
	return (env_path);
}

char	*join_env(char *env, char *cmd)
{
	char	*path;
	char	*half_path;
	char	*dir;
	if (!cmd)
		return (NULL);
	
}

int	main(int ac, char **av, char **envp)
{
	char	*env;

	(void)av;
	(void)ac;
	// while (1)
	// {
	// 	line = readline("---> ");
	// 	path = ft_strjoin("/usr/bin/", *line);
	// 	if (fork() == 0)
	// 	{
	// 		execve(path, line, env);
	// 		perror("execve failed");
	// 		exit(1);
	// 	}
	// 	free(path);
	// }
	// wait(&status);
	env = ft_getenv(envp);
	free (env);
	return (0);
}
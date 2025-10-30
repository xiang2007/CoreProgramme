/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_execute.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchuah <jeremychuahtm@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 15:14:00 by jchuah            #+#    #+#             */
/*   Updated: 2025/10/28 17:21:05 by jchuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <errno.h>
#include "execution.h"

static int	fork_and_execute(char *bin_path, char **argv, t_list **env_vars,
t_shelldata *shelldata)
{
	char	**envp;
	pid_t	pid;
	int		status;

	if (!bin_path)
		return (ERMALLOC);
	envp = create_envp(env_vars, bin_path);
	if (!envp)
		return (ERMALLOC);
	pid = create_shell_child(shelldata);
	if (pid == -1)
	{
		perror("minishell: fork_and_execute");
		return (ERPIPE);
	}
	if (pid == 0)
		clean_execve(bin_path, argv, envp, shelldata);
	free(envp);
	if (waitpid(pid, &status, 0) == -1)
		return (130);
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	return (WTERMSIG(status));
}

static int	set_bin_path(char **bin_path, char *path_env_var, char *cmd)
{
	char	**path_options;
	int		i;

	path_options = ft_split(path_env_var, ":");
	if (!path_options)
		return (ERMALLOC);
	*bin_path = NULL;
	i = 0;
	while (path_options[i])
	{
		*bin_path = path_join(path_options[i], cmd);
		if (!*bin_path)
		{
			ft_strarr_free(path_options);
			return (ERMALLOC);
		}
		if (is_file(*bin_path))
			break ;
		free(*bin_path);
		*bin_path = NULL;
		i++;
	}
	ft_strarr_free(path_options);
	return (0);
}

static int	command_exec(char **argv, char *path_env_var, t_list **env_vars,
t_shelldata *shelldata)
{
	char	*cmd;
	char	*bin_path;
	int		return_val;

	cmd = *argv;
	if (set_bin_path(&bin_path, path_env_var, cmd) != 0)
		return (ERMALLOC);
	if (!bin_path)
	{
		if ((path_env_var[0] == ':'
				|| path_env_var[ft_strlen(path_env_var) - 1] == ':')
			&& is_file(cmd))
			bin_path = ft_strjoin("./", cmd);
		else
		{
			ft_putstrarr_fd((char *[]){cmd, ": command not found\n", NULL}, 2);
			return (127);
		}
	}
	return_val = fork_and_execute(bin_path, argv, env_vars, shelldata);
	free(bin_path);
	return (return_val);
}

static int	absolute_path_exec(char **argv, t_list **env_vars,
t_shelldata *shelldata)
{
	char	*err_str;
	char	*bin_path;
	int		return_val;

	err_str = NULL;
	if (access(*argv, F_OK))
		err_str = ": No such file or directory\n";
	else if (!is_file(*argv))
		err_str = ": Is a directory\n";
	if (err_str)
	{
		ft_putstrarr_fd((char *[]){"minishell: ", *argv, err_str, NULL}, 2);
		if (err_str[2] == 'N')
			return (127);
		return (126);
	}
	bin_path = ft_strdup(*argv);
	if (!bin_path)
		return (ERMALLOC);
	return_val = fork_and_execute(bin_path, argv, env_vars, shelldata);
	free(bin_path);
	return (return_val);
}

int	binary_execute(char **argv, t_shelldata *shelldata)
{
	char	*path_env_var;
	t_list	**env_vars;

	if (!*argv)
		return (0);
	env_vars = &shelldata->env_vars;
	path_env_var = fetch_env_var_value(*env_vars, "PATH");
	if (ft_strchr(*argv, '/') || !path_env_var || !*path_env_var)
		return (absolute_path_exec(argv, env_vars, shelldata));
	else
		return (command_exec(argv, path_env_var, env_vars, shelldata));
}

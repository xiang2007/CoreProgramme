/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_execute_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchuah <jeremychuahtm@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 15:14:00 by jchuah            #+#    #+#             */
/*   Updated: 2025/10/26 23:42:36 by jchuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include "execution.h"

int	is_file(char *path)
{
	struct stat	statbuf;

	if (!path)
		return (0);
	if (stat(path, &statbuf) != 0)
		return (0);
	if (S_ISREG(statbuf.st_mode))
		return (1);
	return (0);
}

char	*path_join(char *path_option, char *cmd)
{
	char	*temp;
	char	*path;

	temp = ft_strjoin(path_option, "/");
	if (!temp)
		return (NULL);
	path = ft_strjoin(temp, cmd);
	free(temp);
	return (path);
}

char	**create_envp(t_list **env_vars, char *bin_path)
{
	char	*underscore_env_var;
	char	**envp;

	underscore_env_var = ft_strjoin("_=", bin_path);
	set_env_var(env_vars, underscore_env_var);
	free(underscore_env_var);
	envp = env_to_array(*env_vars);
	if (!envp)
		return (NULL);
	filter_env_array(envp);
	return (envp);
}

//cleans heredoc_fds before calling execve
//does default cleanup on shelldata if execve fails
//does not use ft_strarr_free on envp because envp uses same char * as env_vars
int	clean_execve(char *bin_path, char *argv[], char *envp[],
t_shelldata *shelldata)
{
	int	exit_code;

	close_heredocs(shelldata->heredoc_fds);
	exit_code = execve(bin_path, argv, envp);
	ft_putstr_fd("minishell: ", 2);
	perror(bin_path);
	free(bin_path);
	ft_strarr_free(argv);
	free(envp);
	clean_exit(shelldata, 126);
	return (exit_code);
}

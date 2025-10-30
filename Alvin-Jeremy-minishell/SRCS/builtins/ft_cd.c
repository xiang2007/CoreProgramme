/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchuah <jeremychuahtm@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 17:43:34 by jchuah            #+#    #+#             */
/*   Updated: 2025/10/29 01:36:07 by jchuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "minishell.h"
#include "builtins.h"

static char	*get_path(char **argv, t_list *env_vars)
{
	char	*path;

	if (!argv[1])
	{
		path = fetch_env_var_value(env_vars, "HOME");
		if (!path)
			ft_putstr_fd("minishell: cd: HOME not set\n", 2);
	}
	else if (ft_strcmp(argv[1], "-") == 0)
	{
		path = fetch_env_var_value(env_vars, "OLDPWD");
		if (!path)
			ft_putstr_fd("minishell: cd: OLDPWD not set\n", 2);
	}
	else
		path = argv[1];
	return (path);
}

static void	update_pwd_vars(char *path, t_list **env_vars)
{
	char	*newpwd;
	char	*newpwd_env_var;
	char	*oldpwd;

	(void)path;
	oldpwd = fetch_env_var_value(*env_vars, "PWD");
	if (!oldpwd)
		set_env_var(env_vars, "OLDPWD");
	else
	{
		oldpwd = ft_strjoin("OLDPWD=", oldpwd);
		if (oldpwd)
			set_env_var(env_vars, oldpwd);
	}
	newpwd = getcwd(NULL, 0);
	newpwd_env_var = ft_strjoin("PWD=", newpwd);
	if (newpwd_env_var)
		set_env_var(env_vars, newpwd_env_var);
	free(oldpwd);
	free(newpwd);
	free(newpwd_env_var);
}

int	ft_cd(char *argv[], t_shelldata *shelldata)
{
	char	*path;

	if (argv[1] && argv[2])
	{
		ft_putstr_fd("minishell: cd: too many arguments\n", 2);
		return (1);
	}
	path = ft_strdup(get_path(argv, shelldata->env_vars));
	if (!path)
		return (1);
	if (*path == '\0')
		return (0);
	if (chdir(path) != 0)
	{
		ft_putstr_fd("minishell: cd: ", 2);
		perror(path);
		free(path);
		return (1);
	}
	if (argv[1] && ft_strcmp(argv[1], "-") == 0)
		printf("%s\n", path);
	update_pwd_vars(path, &shelldata->env_vars);
	free(path);
	return (0);
}

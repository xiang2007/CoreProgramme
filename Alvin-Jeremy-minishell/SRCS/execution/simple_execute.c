/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_execute.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchuah <jeremychuahtm@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 12:12:41 by jchuah            #+#    #+#             */
/*   Updated: 2025/10/28 01:39:55 by jchuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"
#include "builtins.h"

//sets $? to exit code and $_ to last argv
//frees argv
static int	set_exit_vars(int exit_code, char **argv, t_list **env_vars)
{
	char	*nbr_str;
	char	*exit_env_var;
	int		i;

	nbr_str = ft_itoa(exit_code & 0b11111111);
	exit_env_var = ft_strjoin("?=", nbr_str);
	if (nbr_str && exit_env_var)
		set_env_var(env_vars, exit_env_var);
	free(nbr_str);
	free(exit_env_var);
	if (argv && *argv)
	{
		i = 0;
		while (argv[i])
			i++;
		exit_env_var = ft_strjoin("_=", argv[i - 1]);
		if (exit_env_var)
			set_env_var(env_vars, exit_env_var);
		free(exit_env_var);
	}
	ft_strarr_free(argv);
	return (exit_code);
}

//returns -1 if not a builtin
static int	builtin_execute(char **argv, t_shelldata *shelldata)
{
	if (!*argv)
		return (-1);
	if (ft_strcmp(*argv, "echo") == 0)
		return (ft_echo(argv, shelldata));
	else if (ft_strcmp(*argv, "cd") == 0)
		return (ft_cd(argv, shelldata));
	else if (ft_strcmp(*argv, "pwd") == 0)
		return (ft_pwd(argv, shelldata));
	else if (ft_strcmp(*argv, "export") == 0)
		return (ft_export(argv, shelldata));
	else if (ft_strcmp(*argv, "unset") == 0)
		return (ft_unset(argv, shelldata));
	else if (ft_strcmp(*argv, "env") == 0)
		return (ft_env(argv, shelldata));
	else if (ft_strcmp(*argv, "exit") == 0)
		return (ft_exit(argv, shelldata));
	return (-1);
}

static int	redirection_setup(int io_fds_temp[2], t_redir *redirs,
t_shelldata *shelldata)
{
	int	exit_code;

	if (save_io_fds(io_fds_temp) != 0)
		return (ERDUP);
	exit_code = process_redirection(redirs, shelldata);
	if (exit_code != 0)
	{
		if (restore_io_fds(io_fds_temp) != 0)
			return (ERFATAL);
		return (exit_code);
	}
	return (0);
}

int	simple_execute(t_simple *simple, t_shelldata *shelldata)
{
	char	**argv;
	int		exit_code;
	int		io_fds_temp[2];
	t_list	**env_vars;

	env_vars = &shelldata->env_vars;
	argv = build_argv(simple->argv, *env_vars);
	if (!argv)
		return (set_exit_vars(ERMALLOC, argv, env_vars));
	if (simple->redirs)
	{
		exit_code = redirection_setup(io_fds_temp, simple->redirs, shelldata);
		if (exit_code != 0)
			return (set_exit_vars(exit_code, argv, env_vars));
	}
	exit_code = builtin_execute(argv, shelldata);
	if (exit_code == -1)
		exit_code = binary_execute(argv, shelldata);
	if (simple->redirs && restore_io_fds(io_fds_temp) != 0)
		return (set_exit_vars(ERFATAL, argv, env_vars));
	return (set_exit_vars(exit_code, argv, env_vars));
}

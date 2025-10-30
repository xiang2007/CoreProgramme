/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchuah <jchuah@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 14:01:40 by jchuah            #+#    #+#             */
/*   Updated: 2025/10/28 16:05:59 by jchuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "builtins.h"
#include "execution.h"

static void	free_exit(char *argv[], t_shelldata *shelldata, int exit_code)
{
	ft_strarr_free(argv);
	clean_exit(shelldata, exit_code);
}

static void	invalid_arg_exit(char *argv[], t_shelldata *shelldata)
{
	ft_putstr_fd("minishell: exit: ", 2);
	ft_putstr_fd(argv[1], 2);
	ft_putstr_fd(": numeric argument required\n", 2);
	free_exit(argv, shelldata, 2);
}

static t_llong	get_exit_code(char *argv[], t_shelldata *shelldata)
{
	int		i;
	t_llong	exit_code;

	i = 0;
	if (*argv[1] == '\0')
		invalid_arg_exit(argv, shelldata);
	if (*argv[1] == '-' || *argv[1] == '+')
		i++;
	while (argv[1][i])
	{
		if (!ft_isdigit(argv[1][i]))
			invalid_arg_exit(argv, shelldata);
		i++;
	}
	if (ft_atoll_safe(argv[1], &exit_code) != 0)
		invalid_arg_exit(argv, shelldata);
	return (exit_code);
}

int	ft_exit(char *argv[], t_shelldata *shelldata)
{
	t_llong	exit_code;

	if (shelldata->interactive_mode)
		ft_putstr_fd("exit\n", 2);
	if (!argv[1])
		free_exit(argv, shelldata, 0);
	exit_code = get_exit_code(argv, shelldata);
	if (argv[2])
	{
		ft_putstr_fd("minishell: exit: too many arguments\n", 2);
		return (1);
	}
	free_exit(argv, shelldata, exit_code);
	return (255);
}

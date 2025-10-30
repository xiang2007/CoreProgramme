/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchuah <jchuah@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 15:27:05 by jchuah            #+#    #+#             */
/*   Updated: 2025/10/29 03:14:42 by jchuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "builtins.h"

static int	is_n_flag(char *str)
{
	int	n_found;

	n_found = 0;
	if (*str != '-')
		return (0);
	str++;
	while (*str)
	{
		if (*str != 'n')
			return (0);
		else
			n_found = 1;
		str++;
	}
	return (n_found);
}

int	ft_echo(char **argv, t_shelldata *shelldata)
{
	int	n_flag;

	(void)shelldata;
	argv++;
	n_flag = 0;
	while (*argv && is_n_flag(*argv))
	{
		n_flag = 1;
		argv++;
	}
	while (*argv)
	{
		ft_putstr_fd(*argv++, 1);
		if (*argv)
			ft_putstr_fd(" ", 1);
	}
	if (!n_flag)
		ft_putstr_fd("\n", 1);
	return (0);
}

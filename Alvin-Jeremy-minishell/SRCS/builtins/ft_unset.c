/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchuah <jchuah@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 13:48:37 by jchuah            #+#    #+#             */
/*   Updated: 2025/10/25 23:47:54 by jchuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "builtins.h"

int	ft_unset(char *argv[], t_shelldata *shelldata)
{
	argv++;
	while (*argv)
	{
		rm_env_var(&shelldata->env_vars, *argv);
		argv++;
	}
	return (0);
}

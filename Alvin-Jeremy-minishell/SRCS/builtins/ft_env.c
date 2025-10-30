/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchuah <jchuah@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 14:00:22 by jchuah            #+#    #+#             */
/*   Updated: 2025/10/25 23:45:43 by jchuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "builtins.h"

int	ft_env(char *argv[], t_shelldata *shelldata)
{
	(void)argv;
	print_filtered_env(shelldata->env_vars);
	printf("_=env\n");
	return (0);
}

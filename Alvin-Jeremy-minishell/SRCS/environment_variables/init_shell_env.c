/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_shell_env.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchuah <jchuah@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 10:32:30 by jchuah            #+#    #+#             */
/*   Updated: 2025/10/26 14:37:06 by jchuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "minishell.h"
#include "env_vars.h"

//initialises variables like $SHLVL, $0, $? etc.
void	init_shell_env(t_list **env_vars)
{
	int		shlvl;
	char	*shlvl_str;
	char	*shlvl_env_var;

	if (ft_atoi_safe(fetch_env_var_value(*env_vars, "SHLVL"), &shlvl) != 0)
		shlvl = 0;
	shlvl++;
	shlvl_str = ft_itoa(shlvl);
	shlvl_env_var = ft_strjoin("SHLVL=", shlvl_str);
	if (shlvl_env_var)
		set_env_var(env_vars, shlvl_env_var);
	free(shlvl_str);
	free(shlvl_env_var);
	set_env_var(env_vars, "?=0");
}

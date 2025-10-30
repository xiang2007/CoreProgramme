/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_filtered_env.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchuah <jchuah@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 10:38:26 by jchuah            #+#    #+#             */
/*   Updated: 2025/10/26 14:34:57 by jchuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "env_vars.h"

//prints environment, ignoring variables with no set value
void	print_filtered_env(t_list *env_vars)
{
	char	*env_var_str;

	while (env_vars)
	{
		if (env_vars->content)
		{
			env_var_str = (char *)env_vars->content;
			if ((ft_isalpha(*env_var_str) || *env_var_str == '_')
				&& ft_strchr(env_var_str, '=')
				&& ft_strncmp("_=", env_var_str, 2))
				printf("%s\n", env_var_str);
		}
		env_vars = env_vars->next;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fetch_env_var_value_n.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchuah <jchuah@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 14:41:36 by jchuah            #+#    #+#             */
/*   Updated: 2025/10/26 16:10:10 by jchuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "env_vars.h"

//returns a char * pointing to after the '=' of an environment variable name
//returns NULL if var is not set
//variable name is the first n bytes of var_name
char	*fetch_env_var_value_n(t_list *env_vars, char *var_name, size_t n)
{
	char	*env_var_str;

	if (!var_name)
		return (NULL);
	while (env_vars)
	{
		env_var_str = (char *)env_vars->content;
		if (ft_strncmp(env_var_str, var_name, n) == 0)
		{
			env_var_str += n;
			if (*env_var_str == '=')
				return (env_var_str + 1);
			else if (*env_var_str == '\0')
				return (NULL);
		}
		env_vars = env_vars->next;
	}
	return (NULL);
}

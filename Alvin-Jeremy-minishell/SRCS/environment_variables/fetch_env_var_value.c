/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fetch_env_var_value.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchuah <jchuah@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 14:41:36 by jchuah            #+#    #+#             */
/*   Updated: 2025/10/26 14:36:33 by jchuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "env_vars.h"

//returns a char * pointing to after the '=' of an environment variable name
//returns NULL if var is not set
char	*fetch_env_var_value(t_list *env_vars, char *var_name)
{
	char	*env_var_str;
	int		var_name_len;

	if (!var_name)
		return (NULL);
	while (env_vars)
	{
		env_var_str = (char *)env_vars->content;
		var_name_len = ft_strlen(var_name);
		if (ft_strncmp(env_var_str, var_name, var_name_len) == 0)
		{
			env_var_str += var_name_len;
			if (*env_var_str == '=')
				return (env_var_str + 1);
			else if (*env_var_str == '\0')
				return (NULL);
		}
		env_vars = env_vars->next;
	}
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rm_env_var.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchuah <jchuah@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 14:41:36 by jchuah            #+#    #+#             */
/*   Updated: 2025/10/26 14:37:16 by jchuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "env_vars.h"

void	rm_env_var(t_list **env_vars, char *var_name)
{
	char	*env_var_str;
	int		var_name_len;
	t_list	*node_to_del;

	while (*env_vars)
	{
		env_var_str = (char *)(*env_vars)->content;
		var_name_len = ft_strlen(var_name);
		if (ft_strncmp(env_var_str, var_name, var_name_len) == 0)
		{
			env_var_str += var_name_len;
			if (*env_var_str == '=' || *env_var_str == '\0')
			{
				node_to_del = *env_vars;
				*env_vars = node_to_del->next;
				ft_lstdelone(node_to_del, free);
				return ;
			}
		}
		env_vars = &(*env_vars)->next;
	}
}

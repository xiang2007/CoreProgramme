/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchuah <jchuah@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 16:07:39 by jchuah            #+#    #+#             */
/*   Updated: 2025/10/26 14:34:15 by jchuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "env_vars.h"

t_list	*create_env(char *envp[])
{
	t_list	*env_vars;
	t_list	*new_node;
	char	*env_var_str;

	env_vars = NULL;
	while (*envp)
	{
		env_var_str = ft_strdup(*envp);
		new_node = ft_lstnew(env_var_str);
		if (!env_var_str || !new_node)
		{
			free(env_var_str);
			free(new_node);
			ft_lstclear(&env_vars, free);
			return (NULL);
		}
		ft_lstadd_back(&env_vars, new_node);
		envp++;
	}
	return (env_vars);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_env_var.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchuah <jeremychuahtm@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 18:50:35 by jchuah            #+#    #+#             */
/*   Updated: 2025/10/26 14:35:26 by jchuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "env_vars.h"

static int	get_var_name_len(char *str)
{
	int	len;

	len = 0;
	while (str[len] && str[len] != '=')
		len++;
	return (len);
}

static t_list	*create_env_var(char *new_env_var_str)
{
	t_list	*new_node;

	new_env_var_str = ft_strdup(new_env_var_str);
	new_node = ft_lstnew(new_env_var_str);
	if (!new_env_var_str || !new_node)
	{
		free(new_env_var_str);
		free(new_node);
		return (NULL);
	}
	return (new_node);
}

void	set_env_var(t_list **env_vars, char *new_env_var_str)
{
	int		var_name_len;
	char	*env_var_str;

	if (!env_vars || !new_env_var_str)
		return ;
	var_name_len = get_var_name_len(new_env_var_str);
	while (*env_vars)
	{
		env_var_str = (char *)(*env_vars)->content;
		if (ft_strncmp(new_env_var_str, env_var_str, var_name_len) == 0)
		{
			env_var_str += var_name_len;
			if (*env_var_str == '=' || *env_var_str == '\0')
			{
				new_env_var_str = ft_strdup(new_env_var_str);
				if (!new_env_var_str)
					return ;
				free((*env_vars)->content);
				(*env_vars)->content = (void *)new_env_var_str;
				return ;
			}
		}
		env_vars = &(*env_vars)->next;
	}
	(*env_vars) = create_env_var(new_env_var_str);
}

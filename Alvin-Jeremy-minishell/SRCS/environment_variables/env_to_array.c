/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_to_array.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchuah <jchuah@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 16:23:23 by jchuah            #+#    #+#             */
/*   Updated: 2025/10/26 14:35:37 by jchuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "env_vars.h"

char	**env_to_array(t_list *env_vars)
{
	char	**env_array;
	int		env_count;
	int		i;

	env_count = ft_lstsize(env_vars);
	env_array = (char **)malloc((env_count + 1) * sizeof(char *));
	if (!env_array)
		return (NULL);
	i = 0;
	while (i < env_count)
	{
		env_array[i] = (char *)env_vars->content;
		env_vars = env_vars->next;
		i++;
	}
	env_array[i] = NULL;
	return (env_array);
}

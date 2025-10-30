/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter_env_array.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchuah <jchuah@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 09:51:14 by jchuah            #+#    #+#             */
/*   Updated: 2025/10/26 14:36:06 by jchuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "env_vars.h"

//removes exported variables with no set values
void	filter_env_array(char **env_array)
{
	int	i;
	int	j;

	i = 0;
	while (env_array[i])
	{
		if (!ft_strchr(env_array[i], '=')
			|| (ft_strncmp(env_array[i], "?=", 2) == 0))
		{
			j = i;
			while (env_array[j])
			{
				env_array[j] = env_array[j + 1];
				j++;
			}
		}
		else
			i++;
	}
}

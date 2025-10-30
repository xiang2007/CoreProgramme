/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_formatted_env.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchuah <jchuah@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 10:46:46 by jchuah            #+#    #+#             */
/*   Updated: 2025/10/26 14:36:18 by jchuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "env_vars.h"

static int	ft_strcmp_wrapper(const void *a, const void *b)
{
	const char	*s1 = *(const char **)a;
	const char	*s2 = *(const char **)b;

	return (ft_strcmp(s1, s2));
}

static void	print_formatted_variable(char *var_str)
{
	char	*var_val;
	int		var_name_len;

	if (ft_strncmp(var_str, "_=", 2) == 0)
		return ;
	if (!ft_isalpha(*var_str) && *var_str != '_')
		return ;
	printf("declare -x ");
	var_val = ft_strchr(var_str, '=');
	if (!var_val)
	{
		printf("%s\n", var_str);
		return ;
	}
	var_val++;
	var_name_len = (int)(var_val - var_str);
	printf("%.*s\"%s\"\n", var_name_len, var_str, var_val);
}

//prints envrionment sorted by ascii order, prefixed and with values quoted
void	print_formatted_env(t_list *env_vars)
{
	char	**env_array;
	int		env_count;
	int		i;

	env_array = env_to_array(env_vars);
	if (!env_array)
		return ;
	env_count = ft_lstsize(env_vars);
	ft_qsort(env_array, env_count, sizeof(char *), ft_strcmp_wrapper);
	i = 0;
	while (i < env_count)
	{
		print_formatted_variable(env_array[i]);
		i++;
	}
	free(env_array);
}

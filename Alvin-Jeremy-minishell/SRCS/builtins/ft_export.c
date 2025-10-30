/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchuah <jchuah@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 11:56:13 by jchuah            #+#    #+#             */
/*   Updated: 2025/10/25 23:46:13 by jchuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "builtins.h"

//Returns len of variable name
//Returns 0 if variable name is invalid
static int	get_var_name_len(char *var_str)
{
	int	len;

	len = 0;
	if (ft_isdigit(var_str[len]))
		return (0);
	while (var_str[len] && var_str[len] != '=')
	{
		if (!ft_isalnum(var_str[len]) && var_str[len] != '_')
			return (0);
		len++;
	}
	return (len);
}

static int	export_variable(char *var_str, t_list **env_vars)
{
	int	var_name_len;

	var_name_len = get_var_name_len(var_str);
	if (!var_name_len)
	{
		ft_putstr_fd("minishell: export: `", 2);
		ft_putstr_fd(var_str, 2);
		ft_putstr_fd("': not a valid identifier\n", 2);
		return (1);
	}
	if (var_str[var_name_len] == '=')
	{
		set_env_var(env_vars, var_str);
		return (0);
	}
	if (fetch_env_var_value(*env_vars, var_str))
		return (0);
	set_env_var(env_vars, var_str);
	return (0);
}

int	ft_export(char *argv[], t_shelldata *shelldata)
{
	int	errorcount;

	if (!argv[1])
	{
		print_formatted_env(shelldata->env_vars);
		return (0);
	}
	errorcount = 0;
	argv++;
	while (*argv)
	{
		errorcount += export_variable(*argv, &shelldata->env_vars);
		argv++;
	}
	return (!!errorcount);
}

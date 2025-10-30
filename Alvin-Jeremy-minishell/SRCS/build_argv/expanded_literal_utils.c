/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expanded_literal_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchuah <jeremychuahtm@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 10:53:25 by jchuah            #+#    #+#             */
/*   Updated: 2025/10/22 22:22:58 by jchuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "build_argv.h"

//handler functions joins to newstr and moves str_ptr for next section

static void	handle_double_quote_var(char **newstr_ptr, char **str_ptr,
t_list *env_vars)
{
	size_t	var_name_len;
	char	*var_name;
	char	*var_val;
	char	*str;
	char	*temp;

	str = *str_ptr;
	var_name_len = count_var_exp_len(*str_ptr);
	var_name = ft_strndup(str, var_name_len);
	if (!var_name)
	{
		free(*newstr_ptr);
		*newstr_ptr = NULL;
		return ;
	}
	var_val = fetch_env_var_value(env_vars, var_name + 1);
	free(var_name);
	if (var_val)
	{
		temp = ft_strjoin(*newstr_ptr, var_val);
		free(*newstr_ptr);
		*newstr_ptr = temp;
	}
	*str_ptr += var_name_len;
}

static void	handle_double_quote_literal(char **newstr_ptr, char **str_ptr)
{
	size_t	len;
	char	*str;
	char	*temp;

	len = 0;
	str = *str_ptr;
	while (str[len] != '\"' && !is_valid_env_var_exp(&str[len]))
		len++;
	temp = ft_strnjoin(*newstr_ptr, str, len);
	free(*newstr_ptr);
	*newstr_ptr = temp;
	*str_ptr += len;
}

void	handle_double_quote(char **newstr_ptr, char **str_ptr,
t_list *env_vars)
{
	char	*str;

	str = *str_ptr + 1;
	while (*str != '\"')
	{
		if (is_valid_env_var_exp(str))
			handle_double_quote_var(newstr_ptr, &str, env_vars);
		else
			handle_double_quote_literal(newstr_ptr, &str);
	}
	*str_ptr = str + 1;
}

void	handle_single_quote(char **newstr_ptr, char **str_ptr)
{
	size_t	len;
	char	*str;
	char	*temp;

	len = 0;
	str = *str_ptr + 1;
	while (str[len] != '\'')
		len++;
	temp = ft_strnjoin(*newstr_ptr, str, len);
	free (*newstr_ptr);
	*newstr_ptr = temp;
	*str_ptr += len + 2;
}

void	handle_unquoted(char **newstr_ptr, char **str_ptr)
{
	size_t	len;
	char	*str;
	char	*temp;

	len = 0;
	str = *str_ptr;
	while (str[len] && str[len] != '\'' && str[len] != '\"'
		&& str[len] != '*' && !is_valid_env_var_exp(&str[len])
		&& !(str[len] == '$' && (str[len + 1] == '\'' || str[len + 1] == '\"')))
		len++;
	if (len != 0)
	{
		temp = ft_strnjoin(*newstr_ptr, str, len);
		free(*newstr_ptr);
		*newstr_ptr = temp;
	}
	*str_ptr += len;
	if (str[len] == '$' && (str[len + 1] == '\'' || str[len + 1] == '\"'))
		*str_ptr += 1;
}

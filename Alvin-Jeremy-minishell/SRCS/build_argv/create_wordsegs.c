/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_wordsegs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchuah <jeremychuahtm@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 17:21:03 by jchuah            #+#    #+#             */
/*   Updated: 2025/10/15 00:28:53 by jchuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "build_argv.h"

t_wordseg	*create_wildcard_wordseg(char **str_ptr)
{
	size_t		len;
	char		*str;
	char		*newstr;
	t_wordseg	*wordseg;

	str = *str_ptr;
	len = 0;
	while (str[len] == '*')
		len++;
	newstr = ft_strndup(str, len);
	wordseg = (t_wordseg *)malloc(sizeof(t_wordseg));
	if (!wordseg || !newstr)
	{
		free(wordseg);
		free(newstr);
		return (NULL);
	}
	wordseg->str = newstr;
	wordseg->type = WILDCARD;
	*str_ptr += len;
	return (wordseg);
}

t_wordseg	*create_env_var_wordseg(char **str_ptr)
{
	size_t		len;
	char		*str;
	char		*newstr;
	t_wordseg	*wordseg;

	str = *str_ptr;
	len = count_var_exp_len(str);
	newstr = ft_strndup(str, len);
	wordseg = (t_wordseg *)malloc(sizeof(t_wordseg));
	if (!wordseg || !newstr)
	{
		free(wordseg);
		free(newstr);
		return (NULL);
	}
	wordseg->str = newstr;
	wordseg->type = ENV_VAR;
	*str_ptr += len;
	return (wordseg);
}

t_wordseg	*create_expanded_literal_wordseg(char **str_ptr, t_list *env_vars)
{
	char		*newstr;
	t_wordseg	*wordseg;

	newstr = ft_strdup("");
	while (**str_ptr && **str_ptr != '*' && !is_valid_env_var_exp(*str_ptr))
	{
		if (!newstr)
			return (NULL);
		if (**str_ptr == '\"')
			handle_double_quote(&newstr, str_ptr, env_vars);
		else if (**str_ptr == '\'')
			handle_single_quote(&newstr, str_ptr);
		else
			handle_unquoted(&newstr, str_ptr);
	}
	wordseg = (t_wordseg *)malloc(sizeof(t_wordseg));
	if (!wordseg)
	{
		free(newstr);
		return (NULL);
	}
	wordseg->str = newstr;
	wordseg->type = LITERAL;
	return (wordseg);
}

t_wordseg	*create_literal_wordseg(char **str_ptr)
{
	size_t		len;
	char		*str;
	char		*newstr;
	t_wordseg	*wordseg;

	str = *str_ptr;
	len = 0;
	while (str[len] && str[len] != '*')
		len++;
	newstr = ft_strndup(str, len);
	wordseg = (t_wordseg *)malloc(sizeof(t_wordseg));
	if (!wordseg || !newstr)
	{
		free(wordseg);
		free(newstr);
		return (NULL);
	}
	wordseg->str = newstr;
	wordseg->type = LITERAL;
	*str_ptr += len;
	return (wordseg);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchuah <jeremychuahtm@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 14:02:04 by jchuah            #+#    #+#             */
/*   Updated: 2025/10/26 01:51:53 by jchuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "build_argv.h"

int	is_valid_env_var_exp(char *arg)
{
	if (*arg != '$')
		return (0);
	arg++;
	if (!ft_isalpha(*arg) && *arg != '_' && *arg != '?')
		return (0);
	return (1);
}

//Returns len of a variable to be expanded including '$' ($SHLVL gives 6)
//Returns 0 if variable shouldn't be expanded ($234, $, $]{p)
int	count_var_exp_len(char *arg)
{
	int	len;

	len = 0;
	if (arg[len] != '$')
		return (0);
	len++;
	if (arg[len] == '?')
		return (2);
	if (!ft_isalpha(arg[len]) && arg[len] != '_')
		return (0);
	len++;
	while (arg[len] && (ft_isalnum(arg[len]) || arg[len] == '_'))
		len++;
	return (len);
}

int	has_wildcard(t_list *wordlst, int export_on)
{
	t_wordseg	*wordseg;

	while (wordlst && wordlst->content)
	{
		wordseg = (t_wordseg *)wordlst->content;
		if (wordseg->type == WILDCARD)
			return (1);
		if (export_on && ft_strchr(wordseg->str, '='))
			return (0);
		wordlst = wordlst->next;
	}
	return (0);
}

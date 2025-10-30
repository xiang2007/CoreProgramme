/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_wordlst.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchuah <jchuah@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 17:45:43 by jchuah            #+#    #+#             */
/*   Updated: 2025/10/15 00:21:01 by jchuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "build_argv.h"

static t_list	*str_to_wordsegs(char *str, t_list *env_vars)
{
	t_list		*wordlst;
	t_wordseg	*wordseg;
	t_list		*new_node;

	wordlst = NULL;
	while (*str)
	{
		if (*str == '*')
			wordseg = create_wildcard_wordseg(&str);
		else if (is_valid_env_var_exp(str))
			wordseg = create_env_var_wordseg(&str);
		else
			wordseg = create_expanded_literal_wordseg(&str, env_vars);
		new_node = ft_lstnew(wordseg);
		if (!new_node || !wordseg)
		{
			free(new_node);
			free(wordseg);
			ft_lstclear(&wordlst, free_wordseg);
			return (NULL);
		}
		ft_lstadd_back(&wordlst, new_node);
	}
	return (wordlst);
}

t_list	*create_wordlst(char **strarr, t_list *env_vars)
{
	t_list		*wordlst;
	t_list		*new_nodes;
	t_list		*null_node;

	wordlst = NULL;
	while (*strarr)
	{
		new_nodes = str_to_wordsegs(*strarr, env_vars);
		if (!new_nodes)
		{
			ft_lstclear(&wordlst, free_wordseg);
			return (NULL);
		}
		ft_lstadd_back(&wordlst, new_nodes);
		null_node = ft_lstnew(NULL);
		if (!null_node)
		{
			ft_lstclear(&wordlst, free_wordseg);
			return (NULL);
		}
		ft_lstadd_back(&wordlst, null_node);
		strarr++;
	}
	return (wordlst);
}

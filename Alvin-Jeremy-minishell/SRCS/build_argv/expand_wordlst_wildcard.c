/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_wordlst_wildcard.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchuah <jchuah@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 11:24:12 by jchuah            #+#    #+#             */
/*   Updated: 2025/10/26 01:44:20 by jchuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "build_argv.h"

static t_list	*create_wordseg_node(char *str)
{
	char		*newstr;
	t_wordseg	*wordseg;

	newstr = ft_strdup(str);
	if (!newstr)
		return (NULL);
	wordseg = (t_wordseg *)malloc(sizeof(t_wordseg));
	if (!wordseg)
	{
		free(newstr);
		return (NULL);
	}
	wordseg->str = newstr;
	wordseg->type = LITERAL;
	return (ft_lstnew(wordseg));
}

static void	add_null_nodes(t_list **wordlst)
{
	t_list	**origin;
	t_list	*null_node;

	if (!*wordlst)
		return ;
	origin = wordlst;
	while ((*wordlst)->next)
	{
		null_node = ft_lstnew(NULL);
		if (!null_node)
		{
			ft_lstclear(origin, free_wordseg);
			return ;
		}
		null_node->next = (*wordlst)->next;
		(*wordlst)->next = null_node;
		wordlst = &((*wordlst)->next->next);
	}
}

static t_list	*create_expanded_wordlst(t_list *to_expand)
{
	char	**matched_names;
	int		i;
	t_list	*wordlst;
	t_list	*new_node;

	matched_names = get_matching_filenames(to_expand);
	if (!matched_names)
		return (NULL);
	i = 0;
	wordlst = NULL;
	while (matched_names[i])
	{
		new_node = create_wordseg_node(matched_names[i]);
		if (!new_node)
		{
			ft_lstclear(&wordlst, free_wordseg);
			ft_strarr_free(matched_names);
			return (NULL);
		}
		ft_lstadd_back(&wordlst, new_node);
		i++;
	}
	ft_strarr_free(matched_names);
	add_null_nodes(&wordlst);
	return (wordlst);
}

static void	expand_wildcard(t_list **to_expand)
{
	t_list	*expanded_wordlst;
	t_list	**next;

	expanded_wordlst = create_expanded_wordlst(*to_expand);
	if (!expanded_wordlst)
		return ;
	next = to_expand;
	while ((*next)->content)
		next = &(*next)->next;
	ft_lstadd_back(&expanded_wordlst, *next);
	*next = NULL;
	ft_lstclear(to_expand, free_wordseg);
	*to_expand = expanded_wordlst;
}

void	expand_wordlst_wildcard(t_list **wordlst, int export_on)
{
	t_list		**origin;

	origin = wordlst;
	while (*wordlst)
	{
		if ((*wordlst)->content)
		{
			if (has_wildcard(*wordlst, export_on))
			{
				expand_wildcard(wordlst);
				if (!*wordlst)
				{
					ft_lstclear(origin, free_wordseg);
					return ;
				}
			}
			while ((*wordlst)->content)
				wordlst = &(*wordlst)->next;
		}
		else
			wordlst = &(*wordlst)->next;
	}
}

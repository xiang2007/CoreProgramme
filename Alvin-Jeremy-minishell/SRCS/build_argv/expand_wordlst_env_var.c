/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_wordlst_env_var.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchuah <jchuah@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 17:17:39 by jchuah            #+#    #+#             */
/*   Updated: 2025/10/29 02:30:05 by jchuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "build_argv.h"

static	t_list	*str_to_wordsegs(char *str)
{
	t_list		*wordlst;
	t_wordseg	*wordseg;
	t_list		*new_node;

	wordlst = NULL;
	while (*str)
	{
		if (*str == '*')
			wordseg = create_wildcard_wordseg(&str);
		else
			wordseg = create_literal_wordseg(&str);
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

static void	add_null_wrap(t_list **expanded, char *env_var_val, t_list *next)
{
	t_list	*null_node;

	if (*env_var_val && ft_strchr("\n\t ", env_var_val[0]))
	{
		null_node = ft_lstnew(NULL);
		if (!null_node)
		{
			ft_lstclear(expanded, free_wordseg);
			return ;
		}
		ft_lstadd_front(expanded, null_node);
	}
	if (*env_var_val
		&& ft_strchr("\n\t ", env_var_val[ft_strlen(env_var_val) - 1]))
	{
		null_node = ft_lstnew(NULL);
		if (!null_node)
		{
			ft_lstclear(expanded, free_wordseg);
			return ;
		}
		ft_lstadd_back(expanded, null_node);
	}
	ft_lstadd_back(expanded, next);
}

static	t_list	*var_val_split_to_wordlst(char **var_val_split, t_list *next,
char *env_var_val)
{
	t_list	*wordlst;
	t_list	*new_nodes;
	t_list	*null_node;

	if (!var_val_split)
		return (NULL);
	wordlst = NULL;
	while (*var_val_split)
	{
		new_nodes = str_to_wordsegs(*var_val_split);
		ft_lstadd_back(&wordlst, new_nodes);
		if (*(var_val_split + 1))
		{
			null_node = ft_lstnew(NULL);
			ft_lstadd_back(&wordlst, null_node);
		}
		if (!new_nodes || (*(var_val_split + 1) && !null_node))
		{
			ft_lstclear(&wordlst, free_wordseg);
			return (NULL);
		}
		var_val_split++;
	}
	add_null_wrap(&wordlst, env_var_val, next);
	return (wordlst);
}

//expands a single ENV_VAR wordseg node
static void	expand_env_var(t_list **to_expand, t_list *env_vars)
{
	char	*env_var_name;
	char	*env_var_val;
	char	**var_val_split;
	t_list	*new_nodes;

	env_var_name = ((t_wordseg *)(*to_expand)->content)->str + 1;
	env_var_val = fetch_env_var_value(env_vars, env_var_name);
	if (env_var_val == NULL)
		new_nodes = (*to_expand)->next;
	else
	{
		var_val_split = ft_split(env_var_val, "\t\n ");
		new_nodes = var_val_split_to_wordlst(var_val_split, (*to_expand)->next,
				env_var_val);
		if (!new_nodes)
		{
			ft_lstclear(to_expand, free_wordseg);
			return ;
		}
		ft_strarr_free(var_val_split);
	}
	ft_lstdelone(*to_expand, free_wordseg);
	*to_expand = new_nodes;
}

//iterates through wordlst for wordsegs of type ENV_VAR to expand
void	expand_wordlst_env_var(t_list **wordlst, t_list *env_vars)
{
	t_wordseg	*wordseg;
	t_list		**origin;

	origin = wordlst;
	while (*wordlst)
	{
		wordseg = (t_wordseg *)(*wordlst)->content;
		if (wordseg && wordseg->type == ENV_VAR)
		{
			expand_env_var(wordlst, env_vars);
			if (!*wordlst)
			{
				ft_lstclear(origin, free_wordseg);
				return ;
			}
		}
		else
			wordlst = &(*wordlst)->next;
	}
}

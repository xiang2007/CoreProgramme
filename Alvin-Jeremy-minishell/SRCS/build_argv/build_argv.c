/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchuah <jchuah@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 17:17:39 by jchuah            #+#    #+#             */
/*   Updated: 2025/10/27 18:16:53 by jchuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "build_argv.h"

//for debugging
static void	print_argv(char **argv)
{
	ft_putstr_fd("strarr built: ", 2);
	if (!argv)
	{
		ft_putstr_fd("failed\n", 2);
		return ;
	}
	ft_putstr_fd("{", 2);
	while (*argv)
	{
		ft_putstrarr_fd((char *[]){"\"", *argv++, "\"", NULL}, 2);
		if (*argv)
			ft_putstr_fd(", ", 2);
	}
	ft_putstr_fd("}\n=========================\n", 2);
}

static size_t	count_argc(t_list *wordlst)
{
	int			argc;

	argc = 0;
	while (wordlst->next)
	{
		if (wordlst->content && !wordlst->next->content)
			argc++;
		wordlst = wordlst->next;
	}
	return (argc);
}

//moves head of node until it finds a wordseg
//joins strings in wordsegs up till a delimiter wordseg
static char	*join_wordsegs(t_list	**wordlst)
{
	t_wordseg	*wordseg;
	char		*newstr;
	char		*temp;	

	while (*wordlst && !(*wordlst)->content)
		*wordlst = (*wordlst)->next;
	newstr = NULL;
	while ((*wordlst)->content)
	{
		wordseg = (t_wordseg *)(*wordlst)->content;
		temp = ft_strjoin(newstr, wordseg->str);
		free(newstr);
		newstr = temp;
		if (!newstr)
			return (NULL);
		*wordlst = (*wordlst)->next;
	}
	return (newstr);
}

static char	**wordlst_to_argv(t_list *wordlst)
{
	size_t	argc;
	size_t	arg_num;
	char	**argv;
	char	*arg;

	argc = count_argc(wordlst);
	argv = (char **)malloc((argc + 1) * sizeof(char *));
	if (!argv)
		return (NULL);
	arg_num = 0;
	while (arg_num < argc)
	{
		arg = join_wordsegs(&wordlst);
		argv[arg_num] = arg;
		if (!arg)
		{
			ft_strarr_free(argv);
			return (NULL);
		}
		arg_num++;
	}
	argv[arg_num] = NULL;
	return (argv);
}

char	**build_argv(char **strarr, t_list *env_vars)
{
	char	**argv;
	t_list	*wordlst;

	if (!strarr)
		return (NULL);
	if (!*strarr)
		return (ft_strarr_dup(strarr));
	wordlst = create_wordlst(strarr, env_vars);
	if (!wordlst)
		return (NULL);
	expand_wordlst_env_var(&wordlst, env_vars);
	if (!wordlst)
		return (NULL);
	expand_wordlst_wildcard(&wordlst, !ft_strcmp(*strarr, "export"));
	if (!wordlst)
		return (NULL);
	argv = wordlst_to_argv(wordlst);
	ft_lstclear(&wordlst, free_wordseg);
	if (DEBUG)
		print_argv(argv);
	return (argv);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   match_wildcard.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchuah <jchuah@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 16:43:21 by jchuah            #+#    #+#             */
/*   Updated: 2025/10/23 21:44:06 by jchuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "build_argv.h"

static int	recursive_match(t_list *wildcard, char *str)
{
	t_wordseg	*wordseg;
	int			len;

	wordseg = (t_wordseg *)wildcard->content;
	if (!wordseg)
		return (0);
	if (wordseg->type == WILDCARD)
	{
		if (!wildcard->next->content)
			return (1);
		while (*str)
		{
			if (recursive_match(wildcard->next, str))
				return (1);
			str++;
		}
		return (0);
	}
	if (!wildcard->next->content && ft_strcmp(wordseg->str, str) == 0)
		return (1);
	len = ft_strlen(wordseg->str);
	if (ft_strncmp(wordseg->str, str, len))
		return (0);
	return (recursive_match(wildcard->next, str + len));
}

int	match_wildcard(t_list *wildcard, char *str)
{
	t_wordseg	*wordseg;

	if (*str == '.')
	{
		if (ft_strcmp(".", str) == 0 || ft_strcmp("..", str) == 0)
			return (0);
		wordseg = (t_wordseg *)wildcard->content;
		if (*wordseg->str != '.')
			return (0);
	}
	return (recursive_match(wildcard, str));
}

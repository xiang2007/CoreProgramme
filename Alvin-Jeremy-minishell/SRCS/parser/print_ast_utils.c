/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ast2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akok <akok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 13:54:45 by akok              #+#    #+#             */
/*   Updated: 2025/10/28 14:09:52 by akok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "parsing.h"
#include "token.h"

void	print_indent(int depth)
{
	int	i;

	i = -1;
	while (++i < depth)
		printf("    ");
}

void	print_redirs(t_redir *r, int depth)
{
	char	*rtype;

	if (!r)
	{
		print_indent(depth);
		printf("redirs: none\n");
		return ;
	}
	print_indent(depth);
	printf("redirs:\n");
	while (r)
	{
		print_indent(depth + 1);
		if (r->op == REDIR_IN)
			rtype = "<";
		else if (r->op == REDIR_OUT)
			rtype = ">";
		else if (r->op == APPEND)
			rtype = ">>";
		else
			rtype = "<<";
		printf("%s %s (fd=%d)\n", rtype, r->word, r->fd);
		r = r->next;
	}
}

void	print_argv(char **argv, int depth)
{
	int	i;

	print_indent(depth);
	printf("argv: [");
	i = -1;
	if (argv)
	{
		while (argv[++i])
		{
			printf("\"%s\"", argv[i]);
			if (argv[i + 1])
				printf(", ");
		}
	}
	printf("]\n");
}

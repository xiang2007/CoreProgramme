/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ast.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akok <akok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 14:56:07 by akok              #+#    #+#             */
/*   Updated: 2025/10/28 14:10:05 by akok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "parsing.h"
#include "token.h"

void	print_simple(int depth, t_ast *node)
{
	print_indent(depth);
	printf("SIMPLE\n");
	print_argv(node->simple->argv, depth + 1);
	print_redirs(node->simple->redirs, depth + 1);
}

void	print_subshell(int depth, t_ast *node)
{
	print_indent(depth);
	printf("SUBSHELL\n");
	print_indent(depth + 1);
	printf("child:\n");
	print_ast(node->subshell->child, depth + 2);
	print_redirs(node->subshell->redirs, depth + 1);
}

void	print_pipe(int depth, t_ast *node)
{
	t_pipe	*p;

	print_indent(depth);
	printf("PIPELINE\n");
	p = node->pipe;
	while (p)
	{
		print_ast(p->cmd, depth + 1);
		p = p->next;
	}
}

void	print_andor(int depth, t_ast *node)
{
	char	*op;

	print_indent(depth);
	if (node->andor->type == AND_IF)
		op = "&&";
	else
		op = "||";
	printf("AND_OR (%s)\n", op);
	print_indent(depth + 1);
	printf("LEFT:\n");
	print_ast(node->andor->left, depth + 2);
	print_indent(depth + 1);
	printf("RIGHT:\n");
	print_ast(node->andor->right, depth + 2);
}

void	print_ast(t_ast *node, int depth)
{
	if (!node)
		return ;
	if (node->type == SIMPLE)
		print_simple(depth, node);
	else if (node->type == PIPE)
		print_pipe(depth, node);
	else if (node->type == ANDOR)
		print_andor(depth, node);
	else
		print_subshell(depth, node);
}

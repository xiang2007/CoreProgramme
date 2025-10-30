/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akok <akok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 17:49:40 by akok              #+#    #+#             */
/*   Updated: 2025/10/07 13:06:31 by akok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "parsing.h"
#include "token.h"

t_ast	*ast_simple_new(char **argv, t_redir *redirs)
{
	t_ast	*ast_simple;

	ast_simple = ft_calloc(1, sizeof(t_ast));
	if (!ast_simple)
		return (NULL);
	ast_simple->simple = ft_calloc(1, sizeof(t_simple));
	if (!ast_simple->simple)
		return (NULL);
	ast_simple->type = SIMPLE;
	ast_simple->simple->argv = argv;
	ast_simple->simple->redirs = redirs;
	return (ast_simple);
}

t_ast	*ast_subshell_new(t_ast *child, t_redir *redirs)
{
	t_ast	*ast_subshell;

	ast_subshell = ft_calloc(1, sizeof(t_ast));
	if (!ast_subshell)
		return (NULL);
	ast_subshell->subshell = ft_calloc(1, sizeof(t_subshell));
	if (!ast_subshell->subshell)
		return (NULL);
	ast_subshell->type = SUBSHELL;
	ast_subshell->subshell->child = child;
	ast_subshell->subshell->redirs = redirs;
	return (ast_subshell);
}

t_ast	*ast_pipe_new(t_ast *cmd)
{
	t_ast	*ast_pipe;

	ast_pipe = ft_calloc(1, sizeof(t_ast));
	if (!ast_pipe)
		return (NULL);
	ast_pipe->pipe = ft_calloc(1, sizeof(t_pipe));
	if (!ast_pipe->pipe)
		return (NULL);
	ast_pipe->type = PIPE;
	ast_pipe->pipe->cmd = cmd;
	ast_pipe->pipe->next = NULL;
	return (ast_pipe);
}

t_ast	*ast_andor_new(t_andor_type type, t_ast *left, t_ast *right)
{
	t_ast	*ast_andor;

	ast_andor = ft_calloc(1, sizeof(t_ast));
	if (!ast_andor)
		return (NULL);
	ast_andor->andor = ft_calloc(1, sizeof(t_andor));
	if (!ast_andor->andor)
		return (NULL);
	ast_andor->type = ANDOR;
	ast_andor->andor->type = type;
	ast_andor->andor->left = left;
	ast_andor->andor->right = right;
	return (ast_andor);
}

t_redir	*redir_new(t_redir_type op, char *word)
{
	t_redir	*redir;

	redir = ft_calloc(1, sizeof(t_redir));
	if (!redir)
		return (NULL);
	redir->op = op;
	redir->word = word;
	redir->next = NULL;
	return (redir);
}

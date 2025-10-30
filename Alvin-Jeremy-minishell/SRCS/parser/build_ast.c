/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_ast.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akok <akok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 12:42:43 by akok              #+#    #+#             */
/*   Updated: 2025/10/29 01:13:55 by jchuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "parsing.h"
#include "token.h"

static t_ast	*pipeline_append(t_ast *left, t_ast *right);

t_ast	*build_ast(t_token **token_lst, int min_prec)
{
	t_ast	*left;
	t_ast	*right;
	t_token	*op;

	left = parse_primary(token_lst);
	if (!left)
		return (NULL);
	while (tok_is_op(*token_lst) && tok_prec(*token_lst) >= min_prec)
	{
		op = tok_advance(token_lst);
		right = build_ast(token_lst, tok_prec(op) + 1);
		if (!right)
			return (free_ast(left), NULL);
		if (op->token_type == TOK_ANDIF)
			left = ast_andor_new(AND_IF, left, right);
		else if (op->token_type == TOK_ORIF)
			left = ast_andor_new(OR_IF, left, right);
		else if (op->token_type == TOK_PIPE)
			left = pipeline_append(left, right);
	}
	if (min_prec == 0 && !tok_is_eof(*token_lst))
		return (free_ast(left), syntax_error(*token_lst));
	return (left);
}

static t_ast	*pipeline_append(t_ast *left, t_ast *right)
{
	t_pipe	*cur;
	t_pipe	*new_pipe_node;

	if (left->type != PIPE)
		left = ast_pipe_new(left);
	new_pipe_node = ft_calloc(1, sizeof(t_pipe));
	if (!new_pipe_node)
		return (free_ast(left), NULL);
	new_pipe_node->cmd = right;
	new_pipe_node->next = NULL;
	cur = left->pipe;
	while (cur->next)
		cur = cur->next;
	cur->next = new_pipe_node;
	return (left);
}

t_ast	*syntax_error(t_token *token)
{
	ft_putstr_fd("minishell: syntax error near unexpected token `", 2);
	if (token->value)
		ft_putstr_fd(token->value, 2);
	else
		ft_putstr_fd("newline", 2);
	ft_putstr_fd("'\n", 2);
	return (NULL);
}

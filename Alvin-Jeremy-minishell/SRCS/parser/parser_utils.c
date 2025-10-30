/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akok <akok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 10:11:15 by akok              #+#    #+#             */
/*   Updated: 2025/10/28 13:40:58 by akok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "parsing.h"
#include "token.h"

t_token	*tok_advance(t_token **token_lst)
{
	*token_lst = (*token_lst)->next;
	return ((*token_lst)->prev);
}

bool	tok_is_op(t_token *token)
{
	return (token
		&& (token->token_type == TOK_ANDIF
			|| token->token_type == TOK_ORIF
			|| token->token_type == TOK_PIPE));
}

bool	tok_is_paren(t_token *token)
{
	return (token
		&& (token->token_type == TOK_LPAREN
			|| token->token_type == TOK_RPAREN));
}

int	tok_prec(t_token *token)
{
	if (token->token_type == TOK_ANDIF || token->token_type == TOK_ORIF)
		return (1);
	else if (token->token_type == TOK_PIPE)
		return (2);
	return (0);
}

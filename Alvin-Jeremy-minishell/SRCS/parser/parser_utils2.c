/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akok <akok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 13:20:19 by akok              #+#    #+#             */
/*   Updated: 2025/10/28 13:41:28 by akok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "parsing.h"
#include "token.h"

bool	tok_is_redir(t_token *token)
{
	return (token
		&& (token->token_type == TOK_REDIR_IN
			|| token->token_type == TOK_REDIR_OUT
			|| token->token_type == TOK_APPEND
			|| token->token_type == TOK_HEREDOC));
}

bool	tok_is_word(t_token *token)
{
	return (token && token->token_type == TOK_WORD);
}

bool	tok_is_eof(t_token *token)
{
	return (token && token->token_type == TOK_EOF);
}

t_redir_type	get_redir_type(t_token_type token_type)
{
	if (token_type == TOK_REDIR_IN)
		return (REDIR_IN);
	if (token_type == TOK_REDIR_OUT)
		return (REDIR_OUT);
	if (token_type == TOK_APPEND)
		return (APPEND);
	else
		return (HEREDOC);
}

void	append_redir(t_redir **redirs, t_redir *new)
{
	if (redirs == NULL)
		return ;
	while (*redirs)
		redirs = &(*redirs)->next;
	*redirs = new;
}

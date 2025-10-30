/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akok <akok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 15:54:22 by akok              #+#    #+#             */
/*   Updated: 2025/10/28 13:37:09 by akok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "parsing.h"

t_token	*create_new_token(t_token_type t_type, char *value)
{
	t_token	*new_token;

	new_token = (t_token *)malloc(sizeof(t_token));
	if (!new_token)
		return (NULL);
	new_token->token_type = t_type;
	new_token->value = value;
	new_token->prev = NULL;
	new_token->next = NULL;
	return (new_token);
}

void	append_token(t_token **tokens, t_token *new_token)
{
	if (!tokens)
		return ;
	if (!*tokens)
	{
		*tokens = new_token;
		return ;
	}
	while ((*tokens)->next)
		tokens = &((*tokens)->next);
	new_token->prev = *tokens;
	(*tokens)->next = new_token;
}

t_token_type	get_token_type(char *input)
{
	if (ft_strncmp(input, "&&", 2) == 0)
		return (TOK_ANDIF);
	else if (ft_strncmp(input, "||", 2) == 0)
		return (TOK_ORIF);
	else if (ft_strncmp(input, ">>", 2) == 0)
		return (TOK_APPEND);
	else if (ft_strncmp(input, "<<", 2) == 0)
		return (TOK_HEREDOC);
	else if (ft_strncmp(input, "|", 1) == 0)
		return (TOK_PIPE);
	else if (ft_strncmp(input, "<", 1) == 0)
		return (TOK_REDIR_IN);
	else if (ft_strncmp(input, ">", 1) == 0)
		return (TOK_REDIR_OUT);
	else if (ft_strncmp(input, "(", 1) == 0)
		return (TOK_LPAREN);
	else if (ft_strncmp(input, ")", 1) == 0)
		return (TOK_RPAREN);
	else
		return (TOK_INVALID);
}

t_token	*create_word_tok(t_lexer *lexer)
{
	char	*tok_val;
	int		word_len;

	word_len = lexer->p_end - lexer->p_start;
	tok_val = ft_substr(lexer->p_start, 0, word_len);
	if (!tok_val)
		return (NULL);
	lexer->p_start = lexer->p_end;
	return (create_new_token(TOK_WORD, tok_val));
}

t_token	*create_meta_tok(t_lexer *lexer)
{
	int				op_len;
	char			*tok_val;
	t_token_type	tok_type;

	op_len = 1;
	tok_type = get_token_type(lexer->p_start);
	if (tok_type == TOK_INVALID)
		return (NULL);
	if (tok_type == TOK_ANDIF || tok_type == TOK_ORIF
		|| tok_type == TOK_APPEND || tok_type == TOK_HEREDOC)
		op_len += 1;
	tok_val = ft_substr(lexer->p_start, 0, op_len);
	if (!tok_val)
		return (NULL);
	lexer->p_start += op_len;
	return (create_new_token(tok_type, tok_val));
}
/*
void	print_tokens(t_token *tokens)
{
	char	*token[12] = {
		"TOK_ANDIF",
		"TOK_ORIF",
		"TOK_PIPE",
		"TOK_LPAREN",
		"TOK_RPAREN",
		"TOK_REDIR_IN",
		"TOK_REDIR_OUT",
		"TOK_APPEND",
		"TOK_HEREDOC",
		"TOK_WORD",
		"TOK_INVALID",
		"TOK_EOF"
	};
	
	while (tokens)
	{
		printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
	printf("token_type: [%s]\n", token[tokens->token_type]);
		if (!tokens->value)
			printf("token_value: [NULL]\n");
		else
		{
			printf("token: %p; prev: %p; next: %p\n",
					tokens, tokens->prev, tokens->next);
			printf("token_value: [%s]\n", tokens->value);
			
		}
		tokens = tokens->next;
	}
}
*/
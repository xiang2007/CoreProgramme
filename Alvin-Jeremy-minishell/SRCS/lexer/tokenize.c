/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akok <akok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 11:37:19 by akok              #+#    #+#             */
/*   Updated: 2025/10/27 16:41:57 by akok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "parsing.h"

void	reset_lexer(t_lexer *lexer);
void	find_next_token(t_lexer *lexer);
int		append_and_advance(t_lexer *lexer, t_tokendata *shell_data);

int	tokenize(t_tokendata *shell_data)
{
	t_lexer	lexer;

	lexer.p_start = shell_data->input;
	while (*lexer.p_start)
	{
		while (ft_iswhitespace(*lexer.p_start))
			lexer.p_start++;
		if (!*lexer.p_start)
			break ;
		reset_lexer(&lexer);
		find_next_token(&lexer);
		if (append_and_advance(&lexer, shell_data) != SUCCESS)
			return (ft_putendl_fd("minishell: invalid token", 2), FAILURE);
	}
	if (lexer.state != NO_QUOTE)
		return (ft_putendl_fd("minishell: unclosed quotes", 2), FAILURE);
	append_token(&shell_data->token_lst, create_new_token(TOK_EOF, NULL));
	return (SUCCESS);
}

void	reset_lexer(t_lexer *lexer)
{
	lexer->p_end = lexer->p_start;
	lexer->state = NO_QUOTE;
}

void	find_next_token(t_lexer *lexer)
{
	while (*lexer->p_end
		&& (lexer->state != NO_QUOTE
			|| !ft_strchr(METACHARACTERS, *lexer->p_end)))
	{
		if (lexer->state == NO_QUOTE)
		{
			if (*lexer->p_end == '\'')
				lexer->state = IN_QUOTES;
			else if (*lexer->p_end == '"')
				lexer->state = IN_DQUOTES;
		}
		else if ((lexer->state == IN_QUOTES && *lexer->p_end == '\'')
			|| (lexer->state == IN_DQUOTES && *lexer->p_end == '"'))
			lexer->state = NO_QUOTE;
		lexer->p_end++;
	}
}

int	append_and_advance(t_lexer *lexer, t_tokendata *shell_data)
{
	t_token			*new_token;

	if (lexer->p_end > lexer->p_start)
		new_token = create_word_tok(lexer);
	else
		new_token = create_meta_tok(lexer);
	if (!new_token)
		return (FAILURE);
	append_token(&shell_data->token_lst, new_token);
	return (SUCCESS);
}

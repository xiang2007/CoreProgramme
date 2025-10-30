/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_primary_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akok <akok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 15:26:38 by akok              #+#    #+#             */
/*   Updated: 2025/10/28 13:39:42 by akok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "parsing.h"
#include "token.h"

int	parse_redirs(t_token *token, t_token **token_lst, t_redir **redir_lst)
{
	char	*filename;
	t_redir	*redir_node;

	if (token->next->token_type != TOK_WORD)
		return (syntax_error(*token_lst), FAILURE);
	filename = ft_strdup(token->next->value);
	if (!filename)
		return (FAILURE);
	redir_node = redir_new(get_redir_type(token->token_type), filename);
	if (!redir_node)
		return (free(filename), FAILURE);
	append_redir(redir_lst, redir_node);
	tok_advance(token_lst);
	return (SUCCESS);
}

int	parse_argv_and_redirs(t_token **token_lst, char ***argv, t_redir **redirs)
{
	int		i;
	t_token	*token;
	char	*arg_value;

	i = 0;
	while (tok_is_word(*token_lst) || tok_is_redir(*token_lst))
	{
		token = tok_advance(token_lst);
		if (tok_is_word(token))
		{
			arg_value = ft_strdup(token->value);
			(*argv)[i++] = arg_value;
			if (!arg_value)
				return (FAILURE);
		}
		else if (tok_is_redir(token))
		{
			if (parse_redirs(token, token_lst, redirs) != SUCCESS)
				return (FAILURE);
		}
	}
	(*argv)[i] = NULL;
	return (SUCCESS);
}

int	count_argv(t_token *token)
{
	int	count;

	count = 0;
	while (!tok_is_eof(token) && !tok_is_op(token) && !tok_is_paren(token))
	{
		if (tok_is_word(token)
			&& (token->prev == NULL || !tok_is_redir(token->prev)))
			count++;
		token = token->next;
	}
	return (count);
}

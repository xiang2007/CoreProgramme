/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_primary.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akok <akok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 13:20:55 by akok              #+#    #+#             */
/*   Updated: 2025/10/28 13:38:33 by akok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "parsing.h"
#include "token.h"

static t_ast	*parse_subshell(t_token **tokens);
static t_ast	*parse_simple(t_token **tokens);

t_ast	*parse_primary(t_token **token_lst)
{
	if ((*token_lst)->token_type == TOK_LPAREN)
		return (parse_subshell(token_lst));
	return (parse_simple(token_lst));
}

static t_ast	*parse_subshell(t_token **token_lst)
{
	t_ast	*child;
	t_token	*token;
	t_redir	*redirs;

	tok_advance(token_lst);
	child = build_ast(token_lst, 1);
	if (!child)
		return (NULL);
	if ((*token_lst)->token_type != TOK_RPAREN)
		return (free_ast(child), syntax_error(*token_lst));
	tok_advance(token_lst);
	redirs = NULL;
	while (tok_is_redir(*token_lst))
	{
		token = tok_advance(token_lst);
		if (parse_redirs(token, token_lst, &redirs) != SUCCESS)
			return (free_redirs(redirs), NULL);
	}
	return (ast_subshell_new(child, redirs));
}

static t_ast	*parse_simple(t_token **tokens)
{
	char		**argv;
	t_redir		*redir_lst;

	if (!tok_is_word(*tokens) && !tok_is_redir(*tokens))
		return (syntax_error(*tokens));
	argv = NULL;
	redir_lst = NULL;
	argv = ft_calloc(count_argv(*tokens) + 1, sizeof(char *));
	if (!argv)
		return (NULL);
	if (parse_argv_and_redirs(tokens, &argv, &redir_lst) != SUCCESS)
	{
		free_argv(argv);
		free_redirs(redir_lst);
		return (NULL);
	}
	return (ast_simple_new(argv, redir_lst));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akok <akok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 09:11:22 by akok              #+#    #+#             */
/*   Updated: 2025/10/26 16:03:51 by jchuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_H
# define TOKEN_H

# include <stdbool.h>

# define METACHARACTERS " |&;()<>"

typedef enum e_token_type
{
	TOK_ANDIF,
	TOK_ORIF,
	TOK_PIPE,
	TOK_LPAREN,
	TOK_RPAREN,
	TOK_REDIR_IN,
	TOK_REDIR_OUT,
	TOK_APPEND,
	TOK_HEREDOC,
	TOK_WORD,
	TOK_INVALID,
	TOK_EOF
}	t_token_type;

typedef enum e_quote_type
{
	NO_QUOTE,
	IN_QUOTES,
	IN_DQUOTES
}	t_quote_type;

typedef struct s_lexer
{
	char			*p_start;
	char			*p_end;
	t_quote_type	state;
}	t_lexer;

typedef struct s_token
{
	t_token_type	token_type;
	char			*value;
	struct s_token	*next;
	struct s_token	*prev;
}	t_token;

typedef struct s_tokendata
{
	char	*input;
	t_token	*token_lst;
	t_ast	*ast_root;
}	t_tokendata;

#endif

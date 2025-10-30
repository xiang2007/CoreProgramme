/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akok <akok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 11:15:50 by akok              #+#    #+#             */
/*   Updated: 2025/10/28 14:10:22 by akok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# define SUCCESS 0
# define FAILURE 1

# include <signal.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "ast.h"
# include "token.h"

int				tok_prec(t_token *token);
int				count_argv(t_token *token);
int				tokenize(t_tokendata *inputdata);
int				parse_redirs(t_token *token, t_token **token_lst,
					t_redir **redir_lst);
int				parse_argv_and_redirs(t_token **tokens, char ***argv,
					t_redir **redirs);

void			setup_signals(void);
void			free_ast(t_ast *ast);
void			free_argv(char **argv);
void			free_ast_pipe(t_ast *ast);
void			free_ast_andor(t_ast *ast);
void			free_tokens(t_token *token);
void			free_ast_simple(t_ast *ast);
void			restore_default_signals(void);
void			free_ast_subshell(t_ast *ast);
void			print_tokens(t_token *tokens);
void			free_redirs(t_redir *redir_lst);
void			print_ast(t_ast *node, int depth);
void			print_indent(int depth);
void			print_redirs(t_redir *r, int depth);
void			print_argv(char **argv, int depth);
void			append_redir(t_redir **redirs, t_redir *new_redir);
void			append_token(t_token **tokens, t_token *new_token);

bool			tok_is_op(t_token *token);
bool			tok_is_paren(t_token *token);
bool			tok_is_redir(t_token *token);
bool			tok_is_word(t_token *token);
bool			tok_is_eof(t_token *token);

t_ast			*ast_pipe_new(t_ast *cmd);
t_ast			*syntax_error(t_token *token);
t_ast			*parse_primary(t_token **tokens);
t_ast			*ast_simple_new(char **argv, t_redir *redirs);
t_ast			*build_ast(t_token **token_lst, int min_prec);
t_ast			*ast_subshell_new(t_ast *child, t_redir *redirs);
t_ast			*ast_andor_new(t_andor_type type, t_ast *left, t_ast *right);

t_token			*tok_advance(t_token **tokens);
t_token			*create_word_tok(t_lexer *lexer);
t_token			*create_meta_tok(t_lexer *lexer);
t_token			*create_new_token(t_token_type t_type, char *value);

t_redir			*redir_new(t_redir_type op, char *word);

t_token_type	get_token_type(char *input);
t_redir_type	get_redir_type(t_token_type token_type);

#endif

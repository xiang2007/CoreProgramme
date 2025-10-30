/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akok <akok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 09:36:44 by akok              #+#    #+#             */
/*   Updated: 2025/10/26 14:19:31 by jchuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AST_H
# define AST_H

typedef struct s_ast	t_ast;

typedef enum e_node_type
{
	ANDOR,
	PIPE,
	SUBSHELL,
	SIMPLE
}	t_node_type;

typedef enum e_redir_type
{
	REDIR_IN,
	REDIR_OUT,
	APPEND,
	HEREDOC
}	t_redir_type;

typedef enum e_andor_type
{
	AND_IF,
	OR_IF
}	t_andor_type;

typedef struct s_redir
{
	t_redir_type	op;
	int				fd;
	char			*word;
	struct s_redir	*next;
}	t_redir;

typedef struct s_simple
{
	char		**argv;
	t_redir		*redirs;
}	t_simple;

typedef struct s_subshell
{
	t_ast		*child;
	t_redir		*redirs;
}	t_subshell;

typedef struct s_pipe
{
	t_ast			*cmd;
	struct s_pipe	*next;
}	t_pipe;

typedef struct s_andor
{
	t_andor_type	type;
	t_ast			*left;
	t_ast			*right;
}	t_andor;

typedef struct s_ast
{
	t_node_type	type;
	union
	{
		t_simple	*simple;
		t_subshell	*subshell;
		t_pipe		*pipe;
		t_andor		*andor;
	};
}	t_ast;

void	print_ast(t_ast *ast, int depth);
void	free_ast(t_ast *ast);

#endif

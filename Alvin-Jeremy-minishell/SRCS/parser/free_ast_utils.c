/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_ast_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akok <akok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 13:54:47 by akok              #+#    #+#             */
/*   Updated: 2025/10/29 12:40:51 by akok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "parsing.h"

void	free_redirs(t_redir *redir_lst)
{
	t_redir	*next_redir;

	while (redir_lst)
	{
		free(redir_lst->word);
		next_redir = redir_lst->next;
		free(redir_lst);
		redir_lst = next_redir;
	}
}

void	free_ast_simple(t_ast *ast)
{
	if (!ast || !ast->simple)
		return ;
	free_argv(ast->simple->argv);
	free_redirs(ast->simple->redirs);
	free(ast->simple);
	free(ast);
}

void	free_ast_subshell(t_ast *ast)
{
	if (!ast || !ast->subshell)
		return ;
	free_ast(ast->subshell->child);
	free_redirs(ast->subshell->redirs);
	free(ast->subshell);
	free(ast);
}

void	free_ast_pipe(t_ast *ast)
{
	t_pipe	*ast_pipe;
	t_pipe	*next_pipe;

	if (!ast || !ast->pipe)
		return ;
	ast_pipe = ast->pipe;
	while (ast_pipe)
	{
		next_pipe = ast_pipe->next;
		free_ast(ast_pipe->cmd);
		free(ast_pipe);
		ast_pipe = next_pipe;
	}
	free(ast);
}

void	free_ast_andor(t_ast *ast)
{
	if (!ast | !ast->andor)
		return ;
	free_ast(ast->andor->left);
	free_ast(ast->andor->right);
	free(ast->andor);
	free(ast);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_ast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akok <akok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 18:31:04 by akok              #+#    #+#             */
/*   Updated: 2025/10/29 12:36:27 by akok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "parsing.h"
#include "token.h"

void	free_ast(t_ast *ast)
{
	if (!ast)
		return ;
	if (ast->type == SIMPLE)
		free_ast_simple(ast);
	else if (ast->type == PIPE)
		free_ast_pipe(ast);
	else if (ast->type == SUBSHELL)
		free_ast_subshell(ast);
	else if (ast->type == ANDOR)
		free_ast_andor(ast);
}

void	free_argv(char **argv)
{
	int	i;

	i = -1;
	while (argv[++i])
		free(argv[i]);
	free(argv);
}

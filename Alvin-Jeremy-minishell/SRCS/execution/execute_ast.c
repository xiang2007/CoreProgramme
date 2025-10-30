/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_ast.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchuah <jeremychuahtm@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 12:10:01 by jchuah            #+#    #+#             */
/*   Updated: 2025/10/28 17:13:42 by jchuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

static void	set_exit_var(int exit_code, t_shelldata *shelldata)
{
	char	*nbr_str;
	char	*env_var_str;

	exit_code &= 0b11111111;
	nbr_str = ft_itoa(exit_code);
	if (!nbr_str)
	{
		perror("ast set_exit_var");
		return ;
	}
	env_var_str = ft_strjoin("?=", nbr_str);
	free(nbr_str);
	if (!env_var_str)
	{
		perror("ast set_exiv_var");
		return ;
	}
	set_env_var(&shelldata->env_vars, env_var_str);
	free(env_var_str);
}

int	execute_ast(t_ast *ast, t_shelldata *shelldata)
{
	int	exit_code;

	exit_code = 0;
	if (!ast)
		return (0);
	if (ast->type == SIMPLE)
		return (simple_execute(ast->simple, shelldata));
	else if (ast->type == ANDOR)
		return (andor_execute(ast->andor, shelldata));
	else if (ast->type == SUBSHELL)
		exit_code = subshell_execute(ast->subshell, shelldata);
	else if (ast->type == PIPE)
		exit_code = pipe_execute(ast->pipe, shelldata);
	set_exit_var(exit_code, shelldata);
	return (exit_code);
}

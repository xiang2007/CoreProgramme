/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subshell_execute.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchuah <jeremychuahtm@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 01:13:36 by jchuah            #+#    #+#             */
/*   Updated: 2025/10/28 02:05:17 by jchuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

static void	execute(t_subshell *subshell, t_shelldata *shelldata)
{
	int	return_val;

	if (!subshell->redirs)
		return_val = execute_ast(subshell->child, shelldata);
	else
	{
		return_val = process_redirection(subshell->redirs, shelldata);
		if (return_val == 0)
			return_val = execute_ast(subshell->child, shelldata);
	}
	clean_exit(shelldata, return_val);
}

int	subshell_execute(t_subshell *subshell, t_shelldata *shelldata)
{
	pid_t	pid;
	int		status;

	pid = create_shell_child(shelldata);
	if (pid == -1)
	{
		perror("minishell: subshell_execute");
		return (ERFORK);
	}
	if (pid == 0)
		execute(subshell, shelldata);
	if (waitpid(pid, &status, 0) == -1)
		return (130);
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	return (WTERMSIG(status));
}

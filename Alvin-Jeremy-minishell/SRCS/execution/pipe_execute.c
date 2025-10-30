/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_execute.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchuah <jchuah@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 14:17:20 by jchuah            #+#    #+#             */
/*   Updated: 2025/10/28 17:01:46 by jchuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

static int	pipe_child(t_pipes *pipes, int i)
{
	if (i > 0)
	{
		if (dup2(pipes->fds[i - 1][0], 0) == -1)
		{
			perror("minishell");
			close_pipes(pipes);
			return (ERDUP);
		}
	}
	if (i < pipes->count)
	{
		if (dup2(pipes->fds[i][1], 1) == -1)
		{
			perror("minishell");
			close_pipes(pipes);
			return (ERDUP);
		}
	}
	close_pipes(pipes);
	return (0);
}

static int	execute_children(t_pipe *pipe_node, t_shelldata *shelldata,
t_pipes *pipes)
{
	int		exit_code;
	int		i;
	pid_t	pid;

	i = 0;
	while (i <= pipes->count)
	{
		pid = create_shell_child(shelldata);
		if (pid == -1)
			return (ERPIPE);
		if (pid == 0)
		{
			exit_code = pipe_child(pipes, i);
			if (exit_code == 0)
				exit_code = execute_ast(pipe_node->cmd, shelldata);
			clean_exit(shelldata, exit_code);
		}
		pipe_node = pipe_node->next;
		i++;
	}
	close_pipes(pipes);
	return (wait_and_return(pid));
}

int	pipe_execute(t_pipelst *pipelst, t_shelldata *shelldata)
{
	t_pipes	pipes;
	int		exit_code;

	pipes.count = count_pipes(pipelst);
	pipes.fds = (int (*)[2])malloc((pipes.count) * sizeof(int [2]));
	if (!pipes.fds)
		return (ERMALLOC);
	if (open_pipes(&pipes) != 0)
		return (ERPIPE);
	exit_code = execute_children(pipelst, shelldata, &pipes);
	return (exit_code);
}

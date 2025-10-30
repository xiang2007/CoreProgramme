/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchuah <jchuah@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 14:17:20 by jchuah            #+#    #+#             */
/*   Updated: 2025/10/29 12:15:03 by jchuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

int	count_pipes(t_pipelst *pipelst)
{
	int	count;

	count = 0;
	while (pipelst->next)
	{
		count++;
		pipelst = pipelst->next;
	}
	return (count);
}

int	open_pipes(t_pipes *pipes)
{
	int	i;

	i = 0;
	ft_bzero(pipes->fds, sizeof(int [2]) * pipes->count);
	while (i < pipes->count)
	{
		if (pipe(pipes->fds[i]) != 0)
		{
			perror("minishell: open_pipes");
			pipes->fds[i][0] = 0;
			pipes->fds[i][1] = 0;
			close_pipes(pipes);
			return (ERPIPE);
		}
		i++;
	}
	return (0);
}

void	close_pipes(t_pipes *pipes)
{
	int	i;

	i = 0;
	while (i < pipes->count)
	{
		if (pipes->fds[i][0])
			close(pipes->fds[i][0]);
		if (pipes->fds[i][1])
			close(pipes->fds[i][1]);
		pipes->fds[i][0] = 0;
		pipes->fds[i][0] = 0;
		i++;
	}
	free(pipes->fds);
}

int	wait_and_return(pid_t pid)
{
	int	status;

	if (waitpid(pid, &status, 0) == -1)
	{
		while (wait(NULL) != -1)
			;
		return (130);
	}
	while (wait(NULL) != -1)
		;
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	return (WTERMSIG(status));
}

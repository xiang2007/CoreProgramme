/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshou-xi <wshou-xi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 19:28:04 by wshou-xi          #+#    #+#             */
/*   Updated: 2025/09/10 20:03:44 by wshou-xi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/Pipex.h"

int	main(int ac, char **av, char **env)
{
	int		fd[2];
	pid_t	pid1;
	pid_t	pid2;

	if (ac < 5)
		ft_putendl_fd("Error", 2);
	else
	{
		if (pipe(fd) == -1)
			exit (1);
		pid1 = fork();
		if (pid1 == -1)
			exit(EXIT_FAILURE);
		if (pid1 == 0)
			child(av, env, fd);
		pid2 = fork();
		if (pid2 == -1)
			exit(EXIT_FAILURE);
		if (pid2 == 0)
			parent(av, env, fd);
		close_pipe(fd);
		wait_and_exit(pid1, pid2);
	}
}

void	child(char **av, char **env, int *fd)
{
	int	ffd;

	ffd = i_open_file(av[1], 0);
	dup2(ffd, 0);
	dup2(fd[1], 1);
	close (fd[0]);
	exec(av[2], env);
}

void	parent(char **av, char **env, int *fd)
{
	int	ffd;

	ffd = i_open_file(av[4], 1);
	dup2(ffd, 1);
	dup2(fd[0], 0);
	close(fd[1]);
	exec(av[3], env);
}

void	close_pipe(int *fd)
{
	close (fd[0]);
	close (fd[1]);
}

void	wait_and_exit(pid_t pid1, pid_t pid2)
{
	int status;

	waitpid(pid1, NULL, 0);
	waitpid(pid2, &status, 0);
	if (WIFEXITED(status))
		exit(WEXITSTATUS(status));
	else
		exit(1);
}
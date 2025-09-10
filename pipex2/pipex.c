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

#include "Pipex.h"

int	main(int ac, char **av, char **env)
{
	int	fd[2];
	pid_t pid;

	if (ac < 5)
		ft_putendl_fd("Error", 2);
	else
	{
		if (pipe(fd) == -1)
			exit (1);
		if (fork() == -1)
			exit(EXIT_FAILURE);
	}
}

void	child(char **av, char **env, int *fd)
{
	int	ffd;

	ffd = i_open_file(av[0], 0);
	dup2(ffd, 0);
	dup2(fd[1], 1);
	close (fd[0]);
	exe
}

void	parent(char **av, char **env, int *fd)
{
	int	ffd;

	ffd = open(av[5], 1);
	dup2(ffd, 1);
	dup2(fd[0], 0);
	close(fd[1]);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshou-xi <wshou-xi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 17:24:38 by wshou-xi          #+#    #+#             */
/*   Updated: 2025/09/03 17:24:39 by wshou-xi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **env)
{
	pid_t	pid;
	int		fd[2];

	if (ac == 5)
	{
		if (pipe(fd) == -1)
			error (0);
		pid = fork();
		if (pid == -1)
			error (0);
		check_cmd(av[2]);
		check_cmd(av[3]);
		if (pid == 0)
			child_ps(fd, av, env);
		parent_ps(fd, av, env);
		wait(NULL);
	}
	else
	{
		ft_putstr_fd("Error: Bad arguments\n", 2);
		ft_putstr_fd("Ex: ./pipex <infile> <cmd1> <cmd2> <outfile>\n", 2);
	}
	return (0);
}

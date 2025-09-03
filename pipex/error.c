/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshou-xi <wshou-xi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 17:22:14 by wshou-xi          #+#    #+#             */
/*   Updated: 2025/09/03 17:22:15 by wshou-xi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error(int val)
{
	if (val > 1)
	{
		perror("Error");
		exit(127);
	}
	perror("Error");
	exit(EXIT_FAILURE);
}

void	check_cmd(char *cmd)
{
	if (ft_strnstr(cmd, "./", 4) != 0)
	{
		ft_putstr_fd("pipex: command not found: ", 2);
		ft_putendl_fd(cmd, 2);
		exit (0);
	}
	return ;
}

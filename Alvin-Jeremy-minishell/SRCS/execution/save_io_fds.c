/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_io_fds.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchuah <jeremychuahtm@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 19:11:51 by jchuah            #+#    #+#             */
/*   Updated: 2025/10/17 19:15:35 by jchuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

int	save_io_fds(int io_fds[2])
{
	io_fds[0] = dup(0);
	if (io_fds[0] == -1)
	{
		perror("save_io_fds_stdin");
		return (1);
	}
	io_fds[1] = dup(1);
	if (io_fds[1] == -1)
	{
		close(io_fds[0]);
		perror("save_io_fds_stdout");
		return (1);
	}
	return (0);
}

int	restore_io_fds(int io_fds[2])
{
	int	error_code;

	error_code = 0;
	if (dup2(io_fds[0], 0) == -1)
	{
		perror("restore_io_fds_stdin");
		error_code++;
	}
	if (dup2(io_fds[1], 1) == -1)
	{
		perror("restore_io_fds_stdout");
		error_code++;
	}
	close(io_fds[0]);
	close(io_fds[1]);
	return (error_code);
}

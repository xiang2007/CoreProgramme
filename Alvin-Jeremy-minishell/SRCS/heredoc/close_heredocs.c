/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_heredocs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchuah <jeremychuahtm@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 01:19:43 by jchuah            #+#    #+#             */
/*   Updated: 2025/10/25 21:31:39 by jchuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

void	close_heredocs(int heredoc_fds[FD_MAX])
{
	int	i;

	i = 0;
	while (i < FD_MAX)
	{
		if (heredoc_fds[i])
		{
			close(heredoc_fds[i]);
			heredoc_fds[i] = 0;
		}
		i++;
	}
}

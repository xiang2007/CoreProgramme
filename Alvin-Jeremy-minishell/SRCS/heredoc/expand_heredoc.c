/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_heredoc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchuah <jeremychuahtm@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 00:29:31 by jchuah            #+#    #+#             */
/*   Updated: 2025/10/26 01:07:22 by jchuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"
#include "build_argv.h"

static void	remove_heredoc_fd_ref(int fd, int heredoc_fds[FD_MAX])
{
	int	i;

	i = 0;
	while (i < FD_MAX)
	{
		if (heredoc_fds[i] == fd)
		{
			heredoc_fds[i] = 0;
			return ;
		}
		i++;
	}
}

static void	write_expanded_line(t_list *env_vars, int fd, char *line)
{
	int		i;
	int		var_name_len;
	char	*var_value;

	while (*line)
	{
		i = 0;
		while (line[i] && !is_valid_env_var_exp(&line[i]))
			i++;
		write(fd, line, i);
		line += i;
		if (*line)
		{
			var_name_len = count_var_exp_len(line);
			var_value = fetch_env_var_value_n(env_vars, line + 1,
					var_name_len - 1);
			if (var_value)
				write(fd, var_value, ft_strlen(var_value));
			line += var_name_len;
		}
	}
}

void	expand_heredoc(t_redir *redir, t_shelldata *shelldata)
{
	int		pipefds[2];
	char	*line;

	remove_heredoc_fd_ref(redir->fd, shelldata->heredoc_fds);
	if (pipe(pipefds) != 0)
	{
		perror("minishell: expand_heredoc");
		close(redir->fd);
		redir->fd = -1;
		return ;
	}
	line = get_next_line(redir->fd);
	while (line)
	{
		write_expanded_line(shelldata->env_vars, pipefds[1], line);
		free(line);
		line = get_next_line(redir->fd);
	}
	close(redir->fd);
	close(pipefds[1]);
	redir->fd = pipefds[0];
}

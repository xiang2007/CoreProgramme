/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_heredocs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchuah <jeremychuahtm@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 23:19:03 by jchuah            #+#    #+#             */
/*   Updated: 2025/10/29 00:22:32 by jchuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <readline/readline.h>
#include "heredoc.h"
#include "ast.h"
#include "ft_signals.h"

static int	write_to_pipe(int fd, char *eof, t_shelldata *shelldata)
{
	const int	current_line_count = shelldata->line_count;
	char		*line;

	if (!eof)
		return (1);
	line = heredoc_readline("> ", shelldata->interactive_mode);
	while (line && ft_strcmp(eof, line))
	{
		shelldata->line_count++;
		if (write (fd, line, ft_strlen(line)) == -1)
		{
			perror("minishell");
			free(line);
			return (1);
		}
		free(line);
		line = heredoc_readline("> ", shelldata->interactive_mode);
	}
	close(fd);
	if (sigint_check())
		return (HEREDOC_INT);
	if (!line)
		heredoc_eof_msg(eof, current_line_count, shelldata->interactive_mode);
	free(line);
	return (0);
}

static int	write_to_heredoc(t_redir *redir, t_shelldata *shelldata)
{
	int		i;
	int		pipe_fd[2];
	char	*eof;

	i = 0;
	while (i < FD_MAX && shelldata->heredoc_fds[i] != 0)
		i++;
	if (i == FD_MAX)
		return (1);
	if (pipe(pipe_fd) != 0)
		return (1);
	eof = get_eof(redir->word);
	if (write_to_pipe(pipe_fd[1], eof, shelldata) != 0)
	{
		free(eof);
		close(pipe_fd[0]);
		close(pipe_fd[1]);
		return (1);
	}
	free(eof);
	close(pipe_fd[1]);
	redir->fd = pipe_fd[0];
	shelldata->heredoc_fds[i] = pipe_fd[0];
	return (0);
}

int	handle_redir(t_redir *redir, t_shelldata *shelldata)
{
	int	exit_code;

	exit_code = 0;
	while (redir)
	{
		if (redir->op == HEREDOC)
			exit_code = write_to_heredoc(redir, shelldata);
		if (exit_code != 0)
			return (exit_code);
		redir = redir->next;
	}
	return (exit_code);
}

int	handle_pipe(t_pipe *pipelst, t_shelldata *shelldata)
{
	int	exit_code;

	exit_code = 0;
	while (pipelst)
	{
		exit_code = open_heredocs(pipelst->cmd, shelldata);
		if (exit_code != 0)
			return (exit_code);
		pipelst = pipelst->next;
	}
	return (exit_code);
}

int	open_heredocs(t_ast *ast, t_shelldata *shelldata)
{
	int	exit_code;

	if (!ast)
		return (0);
	exit_code = 255;
	if (ast->type == SIMPLE)
		exit_code = handle_redir(ast->simple->redirs, shelldata);
	else if (ast->type == ANDOR)
	{
		exit_code = open_heredocs(ast->andor->left, shelldata);
		if (exit_code == 0)
			exit_code = open_heredocs(ast->andor->right, shelldata);
	}
	else if (ast->type == SUBSHELL)
	{
		exit_code = open_heredocs(ast->subshell->child, shelldata);
		if (exit_code == 0)
			exit_code = handle_redir(ast->subshell->redirs, shelldata);
	}
	else if (ast->type == PIPE)
		exit_code = handle_pipe(ast->pipe, shelldata);
	return (exit_code);
}

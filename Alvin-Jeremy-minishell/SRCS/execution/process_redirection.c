/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_redirection.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchuah <jeremychuahtm@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 12:53:23 by jchuah            #+#    #+#             */
/*   Updated: 2025/10/26 01:10:57 by jchuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

static void	modify_stdin(t_redir *redir, char *target, t_shelldata *shelldata)
{
	if (redir->op == REDIR_IN)
		redir->fd = open(target, O_RDONLY);
	else if (!ft_strchr(redir->word, '\'') && !ft_strchr(redir->word, '\"'))
		expand_heredoc(redir, shelldata);
	if (redir->fd == -1)
		return ;
	if (dup2(redir->fd, 0) == -1)
	{
		close(redir->fd);
		redir->fd = -1;
		return ;
	}
	close(redir->fd);
}

static void	modify_stdout(t_redir *redir, char *target)
{
	if (redir->op == REDIR_OUT)
		redir->fd = open(target, O_WRONLY | O_CREAT | O_TRUNC, 0664);
	else
		redir->fd = open(target, O_WRONLY | O_CREAT | O_APPEND, 0664);
	if (redir->fd == -1)
		return ;
	if (dup2(redir->fd, 1) == -1)
	{
		close(redir->fd);
		redir->fd = -1;
		return ;
	}
	close(redir->fd);
}

static int	set_target(char **target_ptr, char *word, t_list *env_vars)
{
	char	*word_ptr[2];
	char	**expanded_word;

	word_ptr[0] = word;
	word_ptr[1] = NULL;
	expanded_word = build_argv(word_ptr, env_vars);
	if (!expanded_word)
		return (ERMALLOC);
	if (!*expanded_word || *(expanded_word + 1))
	{
		ft_strarr_free(expanded_word);
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(word, 2);
		ft_putstr_fd(": ambiguous redirect\n", 2);
		return (1);
	}
	*target_ptr = *expanded_word;
	free(expanded_word);
	return (0);
}

int	process_redirection(t_redir *redir, t_shelldata *shelldata)
{
	int		exit_code;
	char	*target;

	exit_code = 0;
	target = NULL;
	if (redir->op != HEREDOC)
		exit_code = (set_target(&target, redir->word, shelldata->env_vars));
	if (exit_code != 0)
		return (exit_code);
	if (redir->op == REDIR_OUT || redir->op == APPEND)
		modify_stdout(redir, target);
	else
		modify_stdin(redir, target, shelldata);
	free(target);
	if (redir->fd == -1)
	{
		ft_putstr_fd("minishell: ", 2);
		perror(redir->word);
		return (1);
	}
	if (!redir->next)
		return (0);
	return (process_redirection(redir->next, shelldata));
}

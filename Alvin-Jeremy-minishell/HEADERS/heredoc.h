/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchuah <jeremychuahtm@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 22:20:56 by jchuah            #+#    #+#             */
/*   Updated: 2025/10/29 00:23:23 by jchuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEREDOC_H
# define HEREDOC_H

# include "minishell.h"

char	*heredoc_readline(char *prompt, int interactive_mode);
int		open_heredocs(t_ast *ast, t_shelldata *shelldata);
void	close_heredocs(int heredoc_fds[FD_MAX]);
char	*get_eof(char *word);
void	heredoc_eof_msg(char *eof, const int line_count, int interactive_mode);

#endif

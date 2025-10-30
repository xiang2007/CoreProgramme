/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchuah <jeremychuahtm@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 22:41:43 by jchuah            #+#    #+#             */
/*   Updated: 2025/10/29 00:23:04 by jchuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"
#include "env_vars.h"

#define EOFMSG1 "minishell: warning: here-document at line "
#define EOFMSG2 " delimited by end-of-file (wanted `"
#define EOFMSG3 "')\n"

static void	remove_quotes(char *str)
{
	char	quote;
	int		i;

	while (*str)
	{
		if (*str == '\'' || *str == '\"')
		{
			quote = *str;
			while (*(str + 1) != quote)
			{
				*str = *(str + 1);
				str++;
			}
			i = 0;
			while (str[i + 1])
			{
				str[i] = str[i + 2];
				i++;
			}
		}
		else
			str++;
	}
}

char	*get_eof(char *word)
{
	char	*eof;

	eof = ft_strjoin(word, "\n");
	if (!eof)
		return (NULL);
	remove_quotes(eof);
	return (eof);
}

char	*heredoc_readline(char *prompt, int interactive_mode)
{
	if (interactive_mode)
		ft_putstr_fd(prompt, 2);
	return (get_next_line(0));
}

void	heredoc_eof_msg(char *eof, const int line_count, int interactive_mode)
{
	if (interactive_mode)
		ft_putstr_fd("\n", 2);
	ft_putstr_fd(EOFMSG1, 2);
	ft_putnbr_fd(line_count, 2);
	ft_putstr_fd(EOFMSG2, 2);
	write(2, eof, ft_strlen(eof) - 1);
	ft_putstr_fd(EOFMSG3, 2);
}

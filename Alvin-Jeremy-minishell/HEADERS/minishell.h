/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akok <akok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 16:10:49 by jchuah            #+#    #+#             */
/*   Updated: 2025/10/28 23:55:00 by jchuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include "libft.h"

# define PROMPT			"\001\033[01;32m\0028======D \001\033[0m\002"
# ifndef DEBUG
#  define DEBUG			0
# endif

# define HEREDOC_INT	2
# define FD_MAX			1024

typedef struct s_ast	t_ast;
typedef struct s_shelldata
{
	t_ast	*ast_head;
	t_list	*env_vars;
	int		heredoc_fds[FD_MAX];
	int		head_shell;
	int		interactive_mode;
	int		line_count;
}	t_shelldata;

#endif

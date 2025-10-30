/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchuah <jeremychuahtm@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 21:26:45 by jchuah            #+#    #+#             */
/*   Updated: 2025/10/26 16:31:33 by jchuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <readline/readline.h>
#include "execution.h"

void	clean_exit(t_shelldata *shelldata, int exit_code)
{
	ft_lstclear(&shelldata->env_vars, free);
	free_ast(shelldata->ast_head);
	close_heredocs(shelldata->heredoc_fds);
	rl_clear_history();
	exit(exit_code);
}

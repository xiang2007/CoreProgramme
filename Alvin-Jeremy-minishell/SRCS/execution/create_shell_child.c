/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_shell_child.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchuah <jeremychuahtm@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 21:41:24 by jchuah            #+#    #+#             */
/*   Updated: 2025/10/28 17:41:24 by jchuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "execution.h"
#include "ft_signals.h"

//forks and resets signals for child process
//returns similarly to fork()
pid_t	create_shell_child(t_shelldata *shelldata)
{
	pid_t				pid;
	struct sigaction	sa;

	pid = fork();
	if (pid == -1)
		return (-1);
	if (pid)
	{
		if (!shelldata->interactive_mode && !shelldata->head_shell)
			setup_middle_child_signals();
		return (pid);
	}
	if (!shelldata->head_shell)
		return (pid);
	shelldata->interactive_mode = 0;
	shelldata->head_shell = 0;
	ft_bzero(&sa, sizeof(struct sigaction));
	sa.sa_handler = SIG_DFL;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGINT, &sa, NULL);
	sigaction(SIGQUIT, &sa, NULL);
	return (pid);
}

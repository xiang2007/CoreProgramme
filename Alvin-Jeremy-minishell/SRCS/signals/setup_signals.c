/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_signals.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akok <akok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 18:34:25 by akok              #+#    #+#             */
/*   Updated: 2025/10/29 00:25:27 by jchuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <readline/readline.h>
#include "minishell.h"
#include "heredoc.h"
#include "ft_signals.h"

static void	nonidle_handler(int signum)
{
	if (signum == SIGINT)
	{
		(void)signum;
		write(2, "\n", 1);
		rl_replace_line("", 0);
		rl_on_new_line();
		if (sigint_check() != -1)
			sigint_set(sigint_check() + 1);
		else
			sigint_set(1);
	}
	else if (signum == SIGQUIT)
	{
		ft_putstr_fd("Quit (core dumped)\n", 2);
		sigquit_set(1);
	}
}

void	setup_nonidle_signals(void)
{
	struct sigaction	sa;

	ft_memset(&sa, 0, sizeof(struct sigaction));
	sigemptyset(&sa.sa_mask);
	sa.sa_handler = nonidle_handler;
	sigaction(SIGINT, &sa, NULL);
	sigaction(SIGQUIT, &sa, NULL);
}

static void	idle_handler(int signum)
{
	if (signum == SIGINT)
	{
		write(2, "\n", 1);
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
		if (sigint_check() != -1)
			sigint_set(sigint_check() + 1);
		else
			sigint_set(1);
	}
	else if (signum == SIGQUIT)
		return ;
}

void	setup_idle_signals(void)
{
	struct sigaction	sa;

	ft_memset(&sa, 0, sizeof(struct sigaction));
	sigemptyset(&sa.sa_mask);
	sa.sa_handler = idle_handler;
	sigaction(SIGINT, &sa, NULL);
	sa.sa_handler = SIG_IGN;
	sigaction(SIGQUIT, &sa, NULL);
}

void	setup_middle_child_signals(void)
{
	struct sigaction	sa;

	ft_memset(&sa, 0, sizeof(struct sigaction));
	sigemptyset(&sa.sa_mask);
	sa.sa_handler = SIG_IGN;
	sigaction(SIGINT, &sa, NULL);
	sigaction(SIGQUIT, &sa, NULL);
}

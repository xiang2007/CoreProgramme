/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signals.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchuah <jeremychuahtm@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 00:51:07 by jchuah            #+#    #+#             */
/*   Updated: 2025/10/28 23:36:40 by jchuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SIGNALS_H
# define FT_SIGNALS_H

# include <signal.h>

void	setup_idle_signals(void);
void	setup_nonidle_signals(void);
void	setup_middle_child_signals(void);
int		sigint_check(void);
void	sigint_set(int value);
int		sigquit_check(void);
void	sigquit_set(int value);
void	reset_signals(void);

#endif

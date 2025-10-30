/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sigint_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchuah <jeremychuahtm@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 16:45:31 by jchuah            #+#    #+#             */
/*   Updated: 2025/10/28 01:03:25 by jchuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	sigint_flag_handler(int value, int set)
{
	static int	sig_flag;

	if (set)
		sig_flag = value;
	return (sig_flag);
}

int	sigint_check(void)
{
	return (sigint_flag_handler(0, 0));
}

void	sigint_set(int value)
{
	sigint_flag_handler(value, 1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selow <selow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 17:36:53 by selow             #+#    #+#             */
/*   Updated: 2025/05/19 18:53:58 by selow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	error_msg(void);

/*
	converts a string into an integer
	will check for overflow can print "Error\n"
*/
int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	val;

	i = 0;
	while (str[i] == ' ' || (str[i] <= 13 && str[i] >= 9))
		i++;
	sign = 1;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		sign = -sign;
		i++;
	}
	val = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if ((sign == 1 && val > (INT_MAX - (str[i] - '0')) / 10)
			|| (sign == -1 && val > (-(INT_MIN + (str[i] - '0'))) / 10))
			error_msg();
		val = val * 10 + (str[i] - '0');
		i++;
	}
	return (val * sign);
}

static void	error_msg(void)
{
	ft_printf_fd(2, "Error\n");
	exit(1);
}

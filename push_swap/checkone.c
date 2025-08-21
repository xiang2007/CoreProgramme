/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkone.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshou-xi <wshou-xi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 12:57:05 by wshou-xi          #+#    #+#             */
/*   Updated: 2025/08/21 12:18:46 by wshou-xi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	checkone(char *str)
{
	if (!onlynumbers(str))
		exit (0);
	if (ft_atoi(str) > INT_MAX || ft_atoi(str) < INT_MIN)
		errmsg(NULL, NULL);
}

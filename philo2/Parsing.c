/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshou-xi <wshou-xi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 14:48:33 by wshou-xi          #+#    #+#             */
/*   Updated: 2025/10/14 14:56:02 by wshou-xi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philos.h"

int	checknums(char **av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if (ft_isalnum(av[i]))
			i++;
		return (-1);
	}
	return (0);
}

int	checkarg(int ac, char **av)
{
	
}
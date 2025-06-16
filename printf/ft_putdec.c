/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putdec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshou-xi <wshou-xi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 17:30:31 by wshou-xi          #+#    #+#             */
/*   Updated: 2025/06/14 18:31:19 by wshou-xi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putdec(unsigned int nbr)
{
	char 	*dest;
	int		index;
	int		size;

	index = 0;
	size = ft_count(nbr);
	dest = (char *)malloc(ft_count(nbr));
	if (!dest)
		return (0);
	dest = ft_itoa(nbr);
	while (index < size)
	{
		write(1, &dest[index], 1);
		index++;
	}
	return (index);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 19:12:11 by marvin            #+#    #+#             */
/*   Updated: 2025/06/10 19:12:11 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int nbr)
{
	char	*dest;
	int		index;
	int		size;

	index = 0;
	size = 0;
	if (nbr == -2147483648)
	{
		write(1, "-2147483648", 12);
		return (12);
	}
	if (nbr < 0)
	{
		nbr = -nbr;
		size++;
		write(1, "-", 1);
	}
	if (nbr > 0)
		ft_putnbr(nbr / 10);
	size += ft_putchar((nbr % 10));
	return (size);
}
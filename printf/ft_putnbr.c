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

int	ft_putnbr(long nbr)
{
	int		size;

	if (nbr == -2147483648)
	{
		write(1, "-2147483648", 12);
		return (12);
	}
	size = 0;
	if (nbr < 0)
	{
		nbr = -nbr;
		size++;
		write(1, "-", 1);
	}
	if (nbr >= 10)
		ft_putnbr(nbr / 10);
	size += ft_putchar((nbr % 10) + '0');
	return (size);
}
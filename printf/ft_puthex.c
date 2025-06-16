/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshou-xi <wshou-xi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 11:18:12 by wshou-xi          #+#    #+#             */
/*   Updated: 2025/06/16 11:22:27 by wshou-xi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putlowhex(unsigned long nbr)
{
	char	*lowhex;
	int		index;

	index = 0;
	lowhex = "0123456789abcdef";
	if (nbr >= 16)
		index += ft_putlowhex(nbr / 16);
	write(1, &lowhex[nbr % 16], 1);
	return (index);
}

int	ft_putuphex(unsigned long nbr)
{
	char	*uphex;
	int		index;

	index = 0;
	uphex = "0123456789ABCDEF";
	if (nbr >= 16)
	{
		ft_putuphex(nbr / 16);
		index++;
	}
	write(1, &uphex[nbr % 16], 1);
	return (index);
}

int	ft_puthex(unsigned long nbr, int flag)
{
	if (flag == 1)
		return (ft_putlowhex(nbr));
	else if (flag == 2)
		return (ft_putuphex(nbr));
	else
		return (0);
}
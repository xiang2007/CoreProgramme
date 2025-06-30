/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 22:24:24 by marvin            #+#    #+#             */
/*   Updated: 2025/06/16 22:24:24 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(const char *c)
{
	int	size;
	int	index;

	if (!c)
		return (ft_putstr("(null)"));
	index = 0;
	size = ft_strlen(c);
	while (index < size)
	{
		if (ft_isprint(c[index]))
			write(1, &c[index], 1);
		index++;
	}
	return (size);
}

int	ft_putchar(int c)
{
	char ch;

	ch = (char)c;
	write(1, &ch, 1);
	return (1);
}

int	ft_putdec(unsigned int nbr)
{
	char 	*dest;
	int		index;
	int		size;

	index = 0;
	size = ft_count(nbr);
	dest = ft_itoa(nbr);
	if (!dest)
		return (0);
	ft_putstr(dest);
	free(dest);
	return (index);
}

int	ft_puthex(unsigned long nbr, int sign)
{
	char	*uphex;
	char	*lowhex;
	int		index;

	index = 0;
	lowhex = "0123456789abcdef";
	uphex = "0123456789ABCDEF";
	if (sign == 1)
	{
		if (nbr >= 16)
			index += ft_puthex((nbr / 16),1);
		else
			write(1, &lowhex[nbr % 16], 1);
	}
	else if (sign == 2)
	{
		if (nbr >= 16)	
			index += ft_puthex((nbr / 16),2);
		else
			write(1, &uphex[nbr % 16], 1);
	}
	return (index + 1);
}

int	ft_putnbr(long nbr)
{
	int		size;

	size = 0;
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr = -nbr;
		size++;
	}
	if (nbr >= 10)
		size += ft_putnbr(nbr / 10);
	size += ft_putchar((nbr % 10) + '0');
	return (size);
}

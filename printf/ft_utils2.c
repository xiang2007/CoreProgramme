/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshou-xi <wshou-xi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 22:24:24 by marvin            #+#    #+#             */
/*   Updated: 2025/07/06 11:55:55 by wshou-xi         ###   ########.fr       */
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
	int		size;

	size = ft_count(nbr,10);
	dest = ft_itoa(nbr);
	if (!dest)
		return (0);
	ft_putstr(dest);
	free(dest);
	return (size);
}


int	ft_puthex(unsigned long nbr, int sign)
{
	char	*base;
	char	*buffer;
	int		size;
	int		temp;

	size = ft_count(nbr, 16);
	temp = size;
	buffer = malloc(size + 1);
	if (!buffer)
		return (0);
	if (sign == 1)
		base = LOWHEX;
	if (sign == 2)
		base = UPHEX;
	buffer[size] = '\0';
	while (size--)
	{
		buffer[size] = base[nbr % 16];
		nbr /= 16;
	}
	ft_putstr(buffer);
	free (buffer);
	return (temp);
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

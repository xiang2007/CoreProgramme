/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 22:29:10 by marvin            #+#    #+#             */
/*   Updated: 2025/06/16 22:29:10 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

static int	ft_c(unsigned int n);
static char	*pcha(unsigned int n, int size, int sign);

char	*ft_itoa(unsigned int n)
{
	int	size;
	int	sign;

	sign = 0;
	if (n == 0)
		return (ft_strdup("0"));
	size = ft_c(n);
	return (pcha(n, size, sign));
}

static char	*pcha(unsigned int n, int size, int sign)
{
	char	*dest;
	int		tsize;

	tsize = size + sign;
	dest = (char *)malloc(tsize + 1);
	if (!dest)
		return (NULL);
	dest[tsize] = '\0';
	while (n > 0)
	{
		dest[--tsize] = (n % 10) + '0';
		n /= 10;
	}
	return (dest);
}

static int	ft_c(unsigned int n)
{
	int	size;

	size = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 10;
		size++;
	}
	return (size);
}

int	ft_printvoid(void *ptr)
{
	int	count;

	count = 0;
	if (!ptr)
		return (ft_putstr("(nil)"));
	count += ft_putstr("0x");
	count += ft_puthex((unsigned long)ptr,1);
	return (count);
}
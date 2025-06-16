/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 22:22:20 by marvin            #+#    #+#             */
/*   Updated: 2025/06/16 22:22:20 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_count(unsigned int n)
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

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	else
		return (0);
}

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
	while (index < size)
	{
		write(1, &dest[index], 1);
		index++;
	}
	free(dest);
	return (index);
}
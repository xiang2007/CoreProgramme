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

static char	*pcha(unsigned int n, int size, int sign);

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

char	*ft_itoa(unsigned int n)
{
	int	size;

	if (n == 0)
		return (ft_strdup("0"));
	size = ft_count(n);
	return (pcha(n, size));
}

static char	*pcha(unsigned int n, int size)
{
	char	*dest;

	dest = (char *)malloc(size + 1);
	if (!dest)
		return (NULL);
	dest[size] = '\0';
	while (n > 0)
	{
		dest[--size] = (n % 10) + '0';
		n /= 10;
	}
	return (dest);
}

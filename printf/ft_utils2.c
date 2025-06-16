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

char	*ft_strdup(const char *str)
{
	char	*dst;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(str);
	dst = (char *)malloc(sizeof(char) * (len + 1));
	while (i < len)
	{
		dst[i] = str[i];
		i++;
	}
	dst[len] = '\0';
	return (dst);
}

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_putlowhex(unsigned long nbr)
{
	char	*lowhex;
	int		index;

	index = 0;
	lowhex = "0123456789abcdef";
	if (nbr >= 16)
		index += ft_puthex((nbr / 16),1);
	write(1, &lowhex[nbr % 16], 1);
	return (index + 1);
}

int	ft_putuphex(unsigned long nbr)
{
	char	*uphex;
	int		index;

	index = 0;
	uphex = "0123456789ABCDEF";
	if (nbr >= 16)
		index += ft_puthex((nbr / 16),2);
	write(1, &uphex[nbr % 16], 1);
	return (index + 1);
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
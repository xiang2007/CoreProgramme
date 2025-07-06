/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshou-xi <wshou-xi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 22:22:20 by marvin            #+#    #+#             */
/*   Updated: 2025/07/06 10:35:00 by wshou-xi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_count(unsigned long n, int base)
{
	int	size;

	size = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= base;
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
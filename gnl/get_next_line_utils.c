/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshou-xi <wshou-xi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 19:21:55 by wshou-xi          #+#    #+#             */
/*   Updated: 2025/06/18 11:57:12 by wshou-xi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
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

void	*ft_calloc(size_t nitems, size_t size)
{
	void	*dst;
	char	*dst2;
	size_t	index;
	size_t	max;

	index = 0;
	if (!nitems || size <= 0)
		return (malloc(0));
	max = nitems * size;
	if ((max / nitems) != size)
		return (NULL);
	dst = malloc(nitems * size);
	if (!dst)
		return (NULL);
	dst2 = (char *)dst;
	while (index < max)
	{
		dst2[index] = 0;
		index++;
	}
	return (dst2);
}
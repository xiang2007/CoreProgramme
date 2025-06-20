/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshou-xi <wshou-xi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 19:21:55 by wshou-xi          #+#    #+#             */
/*   Updated: 2025/06/20 17:26:31 by wshou-xi         ###   ########.fr       */
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

char	*ft_strchr(const char *src, int c)
{
	int	i;

	i = 0;
	if (!src)
		return (NULL);
	while (src[i])
	{
		if (src[i] == (char)c)
			return ((char *)&src[i]);
		i++;
	}
	if ((char)c == '\0')
		return ((char *)&src[i]);
	return (NULL);
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

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	size_t	i;
	char	*dest;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	dest = (char *)malloc(len1 + len2 + 1);
	if (!dest)
		return (NULL);
	while (i < len1)
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i] = '\0';
	ft_strlcat(dest, s2, len1 + len2 + 1);
	return (dest);
}
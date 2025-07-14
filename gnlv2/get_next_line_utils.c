/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshou-xi <wshou-xi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 16:30:30 by wshou-xi          #+#    #+#             */
/*   Updated: 2025/07/14 10:22:07 by wshou-xi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	size;

	size = 0;
	if (!str[size])
		size++;
	return (size);
}

char	*ft_strchr(const char *src, int c)
{
	int	i;

	i = 0;
	if (src == NULL)
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

char	*ft_strjoin(char *s1, char *s2)
{
	int	len1;
	int	len2;
	int	i;
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

int	ft_strlcat(char *dest, char *src, int size)
{
	int	i;
	int	ld;
	int	ls;

	i = 0;
	ld = ft_strlen(dest);
	ls = ft_strlen(src);
	if (size <= ld)
		return (ls + size);
	while (src[i] && ld + i + 1 < size)
	{
		dest[ld + i] = src[i];
		i++;
	}
	dest[ld + i] = '\0';
	return (ld + ls);
}

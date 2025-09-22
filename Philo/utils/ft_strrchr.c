/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshou-xi <wshou-xi@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 16:37:27 by wshou-xi          #+#    #+#             */
/*   Updated: 2025/09/22 22:40:46 by wshou-xi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	ft_count(const char *c);

char	*ft_strrchr(const char *s, int c)
{
	int	size;

	size = ft_strlen((char *)s);
	while (size >= 0)
	{
		if (s[size] == (char)c)
			return ((char *)&s[size]);
		size--;
	}
	return (NULL);
}

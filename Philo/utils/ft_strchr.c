/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshou-xi <wshou-xi@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 16:33:10 by wshou-xi          #+#    #+#             */
/*   Updated: 2025/09/22 22:41:26 by wshou-xi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

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

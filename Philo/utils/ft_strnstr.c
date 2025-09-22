/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshou-xi <wshou-xi@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 16:36:56 by wshou-xi          #+#    #+#             */
/*   Updated: 2025/09/22 22:40:56 by wshou-xi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char	*ft_strnstr(const char *find, const char *to_find, size_t len)
{
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	if (!*to_find)
		return ((char *)find);
	i = 0;
	while (find[i] && i < len)
	{
		j = 0;
		while (to_find[j] && find[i + j] == to_find[j] && (i + j) < len)
			j++;
		if (!to_find[j])
			return ((char *)(find + i));
		i++;
	}
	return (NULL);
}

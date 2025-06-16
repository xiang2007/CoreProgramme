/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshou-xi <wshou-xi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 13:59:29 by wshou-xi          #+#    #+#             */
/*   Updated: 2025/06/16 13:59:35 by wshou-xi         ###   ########.fr       */
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
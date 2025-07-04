/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshou-xi <wshou-xi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 16:30:30 by wshou-xi          #+#    #+#             */
/*   Updated: 2025/06/30 17:59:53 by wshou-xi         ###   ########.fr       */
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

char	*readfile(int fd, char	*str)
{
	int	size
	if (!str)
		str = malloc(1);
	
}

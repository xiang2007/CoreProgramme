/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshou-xi <wshou-xi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 19:18:52 by wshou-xi          #+#    #+#             */
/*   Updated: 2025/06/17 17:28:15 by wshou-xi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
	char	*buffer;
	char	*dest;
	int		index;

	index = 0;
	buffer = malloc(BUFFER_SIZE + 1);
	dest = malloc (BUFFER_SIZE + 1);
	read(fd, buffer, BUFFER_SIZE);
	while (dest[index])
	{
		if (dest[index] && dest[index] != '\n')
			dest[index] = buffer[index++];
		
	}
	free(buffer);
	return (dest);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshou-xi <wshou-xi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 19:18:52 by wshou-xi          #+#    #+#             */
/*   Updated: 2025/06/19 16:47:24 by wshou-xi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
	int			bytes_read;
	static char		*buffer;

	buffer = ft_calloc(BUFFER_SIZE + 1 ,sizeof(char));
	if (!buffer)
		return (NULL);
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read <= 0)
		return (NULL);
	return (buffer);
}

char	*strparse(char *str)
{
	int	index;

	index = 0;
	while (str[index] != '\n' || str[index])
	{
		
	}
}

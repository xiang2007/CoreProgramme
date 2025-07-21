/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 10:57:36 by wshou-xi          #+#    #+#             */
/*   Updated: 2025/07/20 09:20:51 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int	fd)
{
	
}

char	*readbuf(char *buffer, int fd)
{
	int	bytes_read;
	
	if (!buffer || buffer[0] == '\0')
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0 && buffer)
	{
		bytes_read = read (fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free (buffer);
			return (NULL);
		}
		if (!ft_strchr(buffer, '/n') && bytes_read > 0)
			ft_strjoin (buffer, )
	}
}

char	*extractline(char *buffer)
{
	int		i;
	char	*temp;

	i = 0;
	if (!buffer)
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	temp = malloc(i + 2);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		temp[i] = buffer[i];
		i++;
	}
	if (buffer[i] = '\n')
		temp[i] = '\n';
	temp[i] = '\0';
	return (temp);
}

char	*polishline(char *buffer)
{
	int		i;
	int		j;
	int		size;
	char	*temp;

	if (!buffer)
		return (NULL);
	size = ft_strlen(buffer);
	i = 0;
	while (buffer[i] && buffer[i] == '\n')
		i++;
	temp = malloc(size + 1);
	if (!temp)
		return (NULL);
	j = 0;
	while (buffer[i] && i <= size)
	{
		temp[j] = buffer[i++];
		j++;
	}
	temp[j] = '\0';
	return (temp);
}

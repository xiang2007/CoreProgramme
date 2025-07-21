/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 10:57:36 by wshou-xi          #+#    #+#             */
/*   Updated: 2025/07/21 22:19:32 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line.h"

char	*get_next_line(int	fd)
{
	static char	*buffer;
	char		*remain;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buffer = readfile(buffer, fd);
	if (!buffer)
		return (NULL);
	remain = extractline(buffer);
	if (!remain)
	{
		free(remain);
		
		return (buffer);
	}
	buffer = polishline(buffer);
	return (remain);
}

char	*readfile(char *buffer, int fd)
{
	int		bytes_read;
	char	*temp;

	bytes_read = 1;
	temp = malloc (BUFFER_SIZE + 1);
	if (!temp)
		return (NULL);
	while (bytes_read > 0 && buffer)
	{
		bytes_read = read(fd, temp, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free (temp);
			return (NULL);
		}
		temp[bytes_read] = '\0';
		buffer = ft_strjoin(buffer, temp);
	}
	free (temp);
	return (buffer);
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

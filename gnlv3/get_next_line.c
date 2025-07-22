/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshou-xi <wshou-xi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 10:57:36 by wshou-xi          #+#    #+#             */
/*   Updated: 2025/07/22 16:27:51 by wshou-xi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*extractline(char *buffer);
char	*readfile(char *buffer, int fd);
char	*polishline(char *buffer);

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
		free(buffer);
		buffer = NULL;
		return (NULL);
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
	while (bytes_read > 0 && !ft_strchr(buffer, '\n'))
	{
		bytes_read = read(fd, temp, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free (temp);
			free (buffer);
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
	if (!buffer || buffer[0] == '\0')
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	temp = malloc(i + 2);
	if (!temp)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		temp[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
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
	while (buffer[i] && (buffer[i] != '\n'))
		i++;
	temp = malloc(i + 1);
	if (!temp)
		return (NULL);
	j = 0;
	while (buffer[i] && i <= size)
	{
		temp[j] = buffer[i];
		i++;
		j++;
	}
	temp[j] = '\0';
	return (temp);
}

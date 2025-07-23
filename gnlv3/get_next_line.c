/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshou-xi <wshou-xi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 10:57:36 by wshou-xi          #+#    #+#             */
/*   Updated: 2025/07/23 17:35:51 by wshou-xi         ###   ########.fr       */
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
		return (NULL);
	buffer = readfile(buffer, fd);
	if (!buffer)
		return (NULL);
	remain = extractline(buffer);
	if (!remain)
	{
		// free(remain);
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
	char	*newbuf;

	temp = malloc (BUFFER_SIZE + 1);
	if (!temp)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0 && !ft_strchr(buffer, '\n'))
	{
		bytes_read = read(fd, temp, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free (temp);
			free (buffer);
			return (NULL);
		}
		temp[bytes_read] = '\0';
		newbuf = ft_strjoin(buffer, temp);
		free (buffer);
		buffer = newbuf;
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
	if (buffer[0] == '\0')
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
		temp[i++] = '\n';
	temp[i] = '\0';
	return (temp);
}

char	*polishline(char *buffer)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	i++;
	temp = malloc(ft_strlen(buffer) - i + 1);
	if (!temp)
	{
		free(buffer);
		return (NULL);
	}
	j = 0;
	while (buffer[i])
		temp[j++] = buffer[i++];
	temp[j] = '\0';
	free(buffer);
	return (temp);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshou-xi <wshou-xi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 19:18:52 by wshou-xi          #+#    #+#             */
/*   Updated: 2025/06/20 19:05:48 by wshou-xi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*readfile(int fd, char *str);

char *get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) > 0)
		return (NULL);
	buffer = readfile(fd,buffer);
	return (buffer);
}

char	*readfile(int fd, char *res)
{
	int	bytes_read;
	char	*buffer;

	if (!res)
		return (ft_calloc(1, 1));
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(buffer);
			return (NULL);
		}
		buffer[BUFFER_SIZE] = '\0';
		res = ft_free(res, buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free (buffer);
	return (res);
}

char	*ft_free(char *src, char *buffer)
{
	char *temp;
	
	temp = ft_strjoin(src, buffer);
	free(buffer);
	return (temp);
}

char	*ft_line(char *buffer)
{
	char	*line;
	int		size;
	int		index;

	index = 0;
	if (!buffer)
		return (NULL);
	size = ft_strlen(buffer);
	line = malloc((size * sizeof(char)) + 1);
	if (!line)
		return (NULL);
	while (line[index] && line[index] != '\n')
	{
		line[index] = buffer[index];
		index++;
	}
}

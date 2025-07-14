/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshou-xi <wshou-xi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 16:30:33 by wshou-xi          #+#    #+#             */
/*   Updated: 2025/07/14 15:07:06 by wshou-xi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*readbuf(int fd, char *str);
char	*extract(char *buffer);
char	*getlast(char *buffer);

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*remain;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = readbuf(fd, buffer);
	remain = extract(buffer);
	if (!remain)
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	buffer = getlast(buffer);
	return (remain);
}

char	*readbuf(int fd, char *str)
{
	char	*temp;
	int		bytes_read;

	temp = malloc(BUFFER_SIZE + 1);
	if(!temp)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0 && !ft(ft_strchr(str, '\n')))
	{
		bytes_read = read(fd, temp, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free (temp);
			return (NULL);
		}
		
	}
	return (temp);
}

char	*extract(char *buffer)
{
	char	*temp;
	int		i;
	int		j;
	int		size;

	i = 0;
	if (!buffer)
		return (NULL);
	size = ft_strlen(buffer);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
	{
		temp = (char *)malloc(i + 1);
		if (!temp)
			return (NULL);
		j = 0;
		while (i != j)
		{
			temp[j] = buffer[j];
			j++;
		}
	}
	temp[i] = '\0';
	return (temp);
}

char	*getlast(char *buffer)
{
	char	*temp;
	int		i;
	int		j;
	int		size;

	j = 0;
	i = 0;
	if (!buffer)
		return (NULL);
	size = ft_strlen(buffer);
	if (!ft_strchr(buffer, '\n'))
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	temp = (char *)malloc(size - i);
	if (!temp)
		return (NULL);
	i++;
	while (i < size)
	{
		temp[j] = buffer[i++];
		j++;
	}
	temp[j] = '\0';
	return (temp);
}

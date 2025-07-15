/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 16:30:33 by wshou-xi          #+#    #+#             */
/*   Updated: 2025/07/15 22:42:35 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*readbuf(int fd, char *str, char *temp);
char	*appendline(char *str, char *remain);
char	*remainder(char *str, int size);
int		nloccur(char *str);

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*remain;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = readbuf(fd, buffer, remain);
	size  = ft_strlen(buffer);
	remain = remainder(buffer);
	if (!remainder)
		return (NULL);
	else if (nloccur(buffer))
	{
		
	}
		

}

char	*readbuf(int fd, char *str, char *temp)
{
	int	bytes_read;

	temp = malloc(BUFFER_SIZE + 1);
	if(!temp)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0 && !ft_strchr(str, '\n'))
	{
		bytes_read = read(fd, temp, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free (str);
			str = NULL;
			return (NULL);
		}
		str = ft_strjoin(str, temp);
	}
	free(temp);
	return (str);
}

char	*extract(char *buffer)
{
	char	*temp;
	int		i;
	int		j;
	int		size;

	i = nloccur(str);
	if (i)
	{
		i++;
		temp = (char *)malloc(i + 1);
		if (!temp)
			return (NULL);
		i++;
		while (str[i])
			temp[j++] = str[i++];
	}
	if(temp)
	{
		temp[j] = '\0';
		return (temp);
	}
	else
		return (NULL);
}

int	nloccur(char *str)
{
	int	i;

	i = 0;
	if (!buffer)
		return (NULL);
	size = ft_strlen(buffer);
	if (!ft_strchr(buffer, '\n'))
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (str[i] == '\n')
		return (i);
	return (0);
}		
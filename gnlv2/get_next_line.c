/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshou-xi <wshou-xi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 16:30:33 by wshou-xi          #+#    #+#             */
/*   Updated: 2025/07/10 14:21:50 by wshou-xi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*readbuf(int fd, char *str, char *temp);
char	*appendline(char *str, char *remain);

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*remain;
	int			flag;

	flag = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = readbuf(fd, buffer, remain);
	buffer = appendline(buffer, remain);

}

char	*readbuf(int fd, char *str, char *temp)
{
	int	bytes_read;

	bytes_read = read(fd, temp, BUFFER_SIZE);
	if (!bytes_read)
		return (0);
	temp[bytes_read] = '\0';
	if (!ft_strchr(str, '\n') && !ft_strchr(str, '\0'))
		str = ft_strjoin(str, temp);
	return (str);
}

char	*appendline(char *str, char *remain)
{
	int	i;
	int	j;
	int	size;

	i = 0;
	j = 0;
	if (!str)
		return (0);
	size = ft_strlen(str);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
	{
		remain = (char *)malloc(size - i);
		while (j < (size - i))
		{
			remain[j] = str[i];
			j++;
			i++;
		}
		str[j + 2] = '\0';
		remain[j] = '\0';
	}
	return (str);
}

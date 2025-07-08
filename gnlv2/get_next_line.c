/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshou-xi <wshou-xi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 16:30:33 by wshou-xi          #+#    #+#             */
/*   Updated: 2025/07/08 16:56:11 by wshou-xi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;
	int			bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = readbuf(fd, buffer);

}

char	*readbuf(int fd, char *str)
{
	char	*temp;
	int		bytes_read;
	int		i;

	i = 0;
	bytes_read = read(fd, temp, BUFFER_SIZE);
	if (!bytes_read)
		return (0);
	temp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!str)
		return (NULL);
	if (!ft_strchr(str, '\n') && !ft_strchr(str, '\0'))
		str = ft_strjoin(str, temp);
	if (ft_strchr(str, '\n'))
		appendline(str);
	free (temp);
	return (str);
}

char	*appendline(char *str)
{
	
}
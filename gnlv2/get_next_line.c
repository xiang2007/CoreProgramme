/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 05:29:28 by marvin            #+#    #+#             */
/*   Updated: 2025/07/12 05:36:40 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*readbuf(int fd, char *str);
char	*remainder(char *str, int size);
int		findnl(char *str);

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*remain;
	int				flag;
	int				size;

	flag = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = readbuf(fd, buffer);
	size  = ft_strlen(buffer);
	remain = remainder(buffer, size);
	if (!remain)
		return (NULL);
	else if (findnl(buffer))
	{
		
	}
		

}

char	*readbuf(int fd, char *str)
{
	char	*temp;
	int	bytes_read;

	bytes_read = read(fd, temp, BUFFER_SIZE);
	if (!bytes_read)
		return (0);
	temp[bytes_read] = '\0';
	if (!ft_strchr(str, '\n') && !ft_strchr(str, '\0'))
		str = ft_strjoin(str, temp);
	return (str);
}

char	*remainder(char *str, int size)
{
	int		i;
	int		j;
	char	*temp;

	i = findnl(str);
	if (i)
	{
		temp = (char *)malloc((size -  i) + 1);
		if (!temp)
			return (NULL);
		str[i] = '\0';
		i++;
		while (str[i])
			temp[j++] = str[i++];
		temp[j] = '\0';
		return (temp);
	}
	else
		return (NULL);
}

int	findnl(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		return (i);
	return (0);
}	

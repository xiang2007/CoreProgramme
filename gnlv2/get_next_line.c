/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshou-xi <wshou-xi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 16:30:33 by wshou-xi          #+#    #+#             */
/*   Updated: 2025/07/09 18:25:58 by wshou-xi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*readbuf(int fd, char *str, char *temp, int flag);
char	*splitline(char *str, char *temp);

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*temp;
	int			flag;

	flag = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = readbuf(fd, buffer, temp, flag);
	if (flag == 1)
	{
		
	}
}

char	*readbuf(int fd, char *str, char *temp, int flag)
{
	int	bytes_read;

	bytes_read = read(fd, temp, BUFFER_SIZE);
	if (!bytes_read)
		return (0);
	temp[BUFFER_SIZE + 1] = '\0';
	if (!ft_strchr(str, '\n') && !ft_strchr(str, '\0'))
		str = ft_strjoin(str, temp);
	if (ft_strchr(str, '\n'))
	{
		flag = 1;
		splitline(str, temp);
	}
	return (str);
}

char	*splitline(char *str, char *temp)
{
	int	i;
	int	j;
	int	size;

	size = ft_strlen(str);
	i = 0;
	j = 0;
	while (str[i] != '\n')
		i++;
	temp = malloc(sizeof(char) * (size - i) + 1);
	if (!temp)
		return (NULL);
	temp[size - i] = '\0';
	while (temp[j])
	{
		temp[j] = str[i];
		str[i] = '\0';
		i++;
		j++;
	}
}

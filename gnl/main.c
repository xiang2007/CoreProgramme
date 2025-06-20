/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshou-xi <wshou-xi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 14:23:20 by wshou-xi          #+#    #+#             */
/*   Updated: 2025/06/20 15:23:38 by wshou-xi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main()
{
	int	fd;
	int	bytes_read = 1;
	char *buffer = calloc(BUFFER_SIZE, sizeof(char));
	char	*next;

	fd = open("test.txt",O_RDONLY);
	while (bytes_read != 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);,
		printf("%s\n",ft_strchr(buffer, '\n'));
	}
	return (0);
}
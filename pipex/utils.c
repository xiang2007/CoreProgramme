/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshou-xi <wshou-xi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 17:24:46 by wshou-xi          #+#    #+#             */
/*   Updated: 2025/09/03 17:24:47 by wshou-xi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_all(char **dptr)
{
	int	i;

	i = 0;
	while (dptr[i])
	{
		free (dptr[i]);
		i++;
	}
	free (dptr);
	return ;
}

int	check_path(char *path)
{
	if (ft_strnstr(path, "/usr/bin/", 9) != 0)
		return (1);
	return (0);
}

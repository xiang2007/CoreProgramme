/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 18:47:31 by marvin            #+#    #+#             */
/*   Updated: 2025/06/10 18:47:31 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(const char *c)
{
	int	size;
	int	index;

	if (!c)
		return (-1);
	index = 0;
	size = ft_strlen(c);
	while (index < size)
	{
		if (ft_isprint(c[index]))
			write(1, &c[index], 1);
		index++;
	}
	return (size);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 20:15:43 by marvin            #+#    #+#             */
/*   Updated: 2025/09/08 20:15:43 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fol.h"

void	ftput_pixel(t_data *img_data, int x, int y, int color)
{
	char	*dst;

	dst = img_data->addr + (y * img_data->line_length + x * (img_data->bpp / 8));
	*(unsigned int *)dst = color;
}
int	get_iter(t_d x, t_d y)
{
	t_cords	cords;
	t_d		z;
	t_d		res;
	int		iter;

	cords.res_c = 0;
	z = 1;
	iter = 0;
	while (z < 4 && iter < MAX_ITER)
	{
		cords.res_c = (x * 0.005) + (y * 0.0033);
		res = d_square(z) + cords.res_c;
		z = res;
		iter++;
	}
	return (iter);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xiang <xiang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 00:30:59 by marvin            #+#    #+#             */
/*   Updated: 2025/12/06 16:37:41 by xiang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fol.h"

static int	interpolate_color(int c1, int c2, t_d t)
{
	t_color	color;
	int		r;
	int		g;
	int		b;

	color.r1 = (c1 >> 16) & 0xFF;
	color.g1 = (c1 >> 8) & 0xFF;
	color.b1 = c1 & 0xFF;
	color.r2 = (c2 >> 16) & 0xFF;
	color.g2 = (c2 >> 8) & 0xFF;
	color.b2 = c2 & 0xFF;
	r = (int)((1 - t) * color.r1 + t * color.r2);
	g = (int)((1 - t) * color.g1 + t * color.g2);
	b = (int)((1 - t) * color.b1 + t * color.b2);
	return ((r << 16) | (g << 8) | b);
}

static int	get_color(t_d n, int iter, t_data *data)
{
	t_d		res;
	t_d		f;
	t_color	color;
	int		i;
	int		*palette[6] = (RED, ORANGE, YELLOW, GREEN, BLUE, DBLUE, PURPLE);

	res = 0;
	if (iter == MAX_ITER)
		return (BLACK);
	res = ((iter + 1) - (log(log(fabs(n)))) / log(2));
	f = res - floor(res);
	color.color_number = data->color_num;
	i = ((int)floor(res)) % color.color_number;
	color.c1 = palette[i];
	color.c2 = palette[(i + 1) % color.color_number];
	free(palette);
	return (interpolate_color(color.c1, color.c2, f));
}

int	julia_iter(int x, int y, t_d *z_last, t_data *data)
{
	t_xy	z;
	t_d		xtemp;
	int		iter;

	z.x = get_x_scaled(x, data->zoom, data->x, data);
	z.y = get_y_scaled(y, data->zoom, data->y, data);
	iter = 0;
	data->cx = data->jcx;
	data->cy = data->jcy;
	while (d_sq(z.x) + d_sq(z.y) < 4 && iter < MAX_ITER)
	{
		xtemp = d_sq(z.x) - d_sq(z.y);
		z.y = 2 * z.x * z.y + data->cy;
		z.x = xtemp + data->cx;
		iter++;
	}
	*z_last = sqrt((z.x * z.x) + (z.y * z.y));
	return (iter);
}

void	put_julia(void *img, t_data *data)
{
	t_iter	iter;
	t_d		z_last;

	iter.j = 0;
	z_last = 0;
	iter.color = 0;
	data->jl = 1;
	while (iter.j < HEIGHT)
	{
		iter.i = 0;
		while (iter.i < WIDTH)
		{
			iter.iter = julia_iter(iter.i, iter.j, &z_last, data);
			iter.color = get_color(z_last, iter.iter, data);
			ftput_pixel(img, iter.i, iter.j, iter.color);
			iter.i++;
		}
		iter.j++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshou-xi <wshou-xi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 16:18:25 by wshou-xi          #+#    #+#             */
/*   Updated: 2025/09/11 17:31:15 by wshou-xi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fol.h"

int	interpolate_color(int c1, int c2, t_d t)
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

int	get_color(t_d n, int iter)
{
	t_d		res;
	t_d		f;
	t_color	color;
	int		i;
	int		palette[7] = {RED, ORANGE, YELLOW, GREEN, BLUE,
				DBLUE, PURPLE};

	res = 0;
	if (iter == MAX_ITER)
		return (BLACK);
	res = ((iter + 1) - (log(log(fabs(n)))) / log(2));
	f = res - floor(res);
	color.color_number = 7;
	i = ((int)floor(res)) % color.color_number;
	color.c1 = palette[i];
	color.c2 = palette[(i + 1) % color.color_number];
	return (interpolate_color(color.c1, color.c2, f));
}

int	get_iter(int x, int y, t_d *z_last, t_data *ct)
{
	t_calc	calc;
	t_xy	xy;
	int		iter;

	iter = 0;
	xy.x0 = get_x_scaled(x, ct->zoom, ct->x, ct-> y);
	xy.y0 = get_y_scaled(y, ct->zoom, ct->x, ct-> y);
	xy.x = 0;
	xy.y = 0;
	xy.x2 = 0;
	xy.y2 = 0;
	calc.temp = 0;
	while ((xy.x2 + xy.y2 <= 4) && iter < MAX_ITER)
	{
		xy.y = 2 * xy.x * xy.y + xy.y0;
		xy.x = xy.x2 - xy.y2 + xy.x0;
		xy.x2 = d_sq(xy.x);
		xy.y2 = d_sq(xy.y);
		iter++;
	}
	*z_last = sqrt(xy.x2 + xy.y2);
	return (iter);
}

void	put_mandel(void *img, t_data *control)
{
	t_iter iter;
	t_d	z_last;

	iter.j = 0;
	z_last = 0;
	iter.color = 0;
	while (iter.j <= HEIGTH)
	{
		iter.i = 0;
		while (iter.i <= WIDTH)
		{
			iter.iter = get_iter(iter.i, iter.j, &z_last, control);
			iter.color = get_color(z_last, iter.iter);
			ftput_pixel(img, iter.i, iter.j, iter.color);
			iter.i++;
		}
		iter.j++;
	}
}


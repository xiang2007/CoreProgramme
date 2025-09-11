/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 16:18:25 by wshou-xi          #+#    #+#             */
/*   Updated: 2025/09/11 07:09:11 by marvin           ###   ########.fr       */
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

int	get_iter(int x, int y, t_d *z_last)
{
	t_calc	calc;
	t_xy	xy;
	int		iter;

	iter = 0;
	xy.x0 = get_x_scaled(x);
	xy.y0 = get_y_scaled(y);
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

void	put_mandel(void *img)
{
	int	i;
	int	j;
	int	iter;
	int	color;
	t_d	z_last;

	j = 0;
	z_last = 0;
	color = 0;
	while (j <= HEIGTH)
	{
		i = 0;
		while (i <= WIDTH)
		{
			iter = get_iter(i, j, &z_last);
			color = get_color(z_last, iter);
			ftput_pixel(img, i, j, color);
			i++;
		}
		j++;
	}
}


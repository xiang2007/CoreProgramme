#include <stdio.h>
#include "header.h"

/*t_d	d_sq(t_d num)
{
	return (num * num);
}

t_d	get_x_scaled(t_d x, t_d zoom, t_d sx, t_data *data)
{
	if (data->mandel)
		return ((-2 + ((x / (WIDTH - 1)) * 3)) / zoom + sx);
	else
		return ((-2 + (x / (WIDTH - 1)) * 4) / zoom + sx);
}

t_d	get_y_scaled(t_d y, t_d zoom, t_d sy, t_data *data)
{
	if (data->mandel)
		return ((-1.135 + (y / (HEIGHT - 1)) * 2.27) / zoom + sy);
	else
		return ((-2 + (y / (HEIGHT - 1)) * 4) / zoom + sy);
}

static int	*asign_color(int *temp)
{
	temp[0] = RED;
	temp[1] = ORANGE;
	temp[2] = YELLOW;
	temp[3] = GREEN;
	temp[4] = BLUE;
	temp[5] = DBLUE;
	temp[6] = PURPLE;
	return (temp);
}*/

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

/*int	get_color(t_d n, int iter, t_data *data)
{
	t_d		res;
	t_d		f;
	t_color	color;
	int		i;
	int		*palette;

	if (iter == MAX_ITER)
		return (BLACK);
	palette = (int *)malloc(sizeof(int) * 7);
	palette = asign_color(palette);
	res = 0;
	res = ((iter + 1) - (log(log(fabs(n)))) / log(2));
	f = res - floor(res);
	color.color_number = data->color_num;
	i = ((int)floor(res)) % color.color_number;
	color.c1 = palette[i];
	color.c2 = palette[(i + 1) % color.color_number];
	free (palette);
	return (interpolate_color(color.c1, color.c2, f));
}

int	get_iter(int x, int y, t_d *z_last, t_data *data)
{
	t_xy	xy;
	int		iter;

	iter = 0;
	xy.x0 = get_x_scaled(x, data->zoom, data->x, data);
	xy.y0 = get_y_scaled(y, data->zoom, data->y, data);
	xy.x = 0;
	xy.y = 0;
	xy.x2 = 0;
	xy.y2 = 0;
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
}*/


int	main(void)
{
	int color;
	color = interpolate_color(RED, YELLOW, 0.123);
	printf("Color is %x\n", color);
	return (0);
}

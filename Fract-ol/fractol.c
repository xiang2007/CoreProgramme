/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshou-xi <wshou-xi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 16:18:25 by wshou-xi          #+#    #+#             */
/*   Updated: 2025/09/09 12:03:28 by wshou-xi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fol.h"

void	ftput_pixel(t_data *img_data, int x, int y, int color)
{
	char	*dst;

	dst = img_data->addr + (int)(y * img_data->line_length + x * (img_data->bpp / 8));
	*(unsigned int *)dst = color;
}

int	get_iter(int x, int y)
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
	return (iter);
}

void	put_mandel(void *img)
{
	int	i;
	int	j;
	int	iter;

	i = 0;
	j = 0;
	while (j <= HEIGTH)
	{
		while (i <= 800)
		{
			iter = get_iter(i, j);
			if (iter == MAX_ITER)
				ftput_pixel(img, i, j, BLACK);
			else if (iter % 2 == 0)
				ftput_pixel(img, i, j, BLUE);
			else if (iter % 3 == 0)
				ftput_pixel(img, i, j, PURPLE);
			else
				ftput_pixel(img, i, j, WHITE);
			i++;
		}
		i = 0;
		j++;
	}
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data		img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, WIDTH, HEIGTH, "hello");
	img.img = mlx_new_image(mlx, WIDTH, HEIGTH);
	img.addr = mlx_get_data_addr(img.img, &img.bpp,
								&img.line_length, &img.endian);
	put_mandel(&img.img);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
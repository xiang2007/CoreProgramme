/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshou-xi <wshou-xi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 16:18:25 by wshou-xi          #+#    #+#             */
/*   Updated: 2025/09/08 16:49:18 by wshou-xi         ###   ########.fr       */
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

int	main(void)
{
	//void	*mlx;
	//void	*mlx_win;
	//t_data		img;

	/*mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, WIDTH, HEIGTH, "hello");
	img.img = mlx_new_image(mlx, WIDTH, HEIGTH);
	img.addr = mlx_get_data_addr(img.img, &img.bpp,
								&img.line_length, &img.endian);*/
	printf("max iter is: %d\n",get_iter(100, 100));
	//mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	//mlx_loop(mlx);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 07:08:27 by marvin            #+#    #+#             */
/*   Updated: 2025/09/11 07:08:27 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fol.h"

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
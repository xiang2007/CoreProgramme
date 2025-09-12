/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshou-xi <wshou-xi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 07:08:27 by marvin            #+#    #+#             */
/*   Updated: 2025/09/11 16:45:45 by wshou-xi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fol.h"

int	main(void)
{
	t_data		img;

	img.mlx = mlx_init();
	img.mlx_win = mlx_new_window(img.mlx, WIDTH, HEIGTH, "im gay");
	img.img = mlx_new_image(img.mlx, WIDTH, HEIGTH);
	img.addr = mlx_get_data_addr(img.img, &img.bpp,
								&img.line_length, &img.endian);
	img.zoom = 1;
	img.x = 0;
	img.y = 0;
	put_mandel(&img.img, &img);
	mlx_put_image_to_window(img.mlx, img.mlx_win, img.img, 0, 0);
	mlx_hook(img.mlx_win, 2, 1L<<0, handle_press, &img);
	mlx_loop(img.mlx);
}
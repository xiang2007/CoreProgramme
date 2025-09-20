/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 07:08:27 by marvin            #+#    #+#             */
/*   Updated: 2025/09/20 01:44:51 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fol.h"

void	asign_value(t_data *img, int ac, char **av)
{
	img->zoom = 1;
	img->x = 0;
	img->y = 0;
	img->mx = 0.1;
	img->my = 0.1;
	img->jcx = -0.5125;
	img->jcy = 0.5125;
	img->jl = 0;
	img->mandel = 0;
	img->color_num = 7;
	if (ac == 3)
	{
		close_all(img);
		ft_putendl_fd("Set available: 1.Mandlbrot 2.Julia", 1);
	}
	if (ac > 1 && av[2] && av[3])
	{
		img->jcx = ft_atof(av[2]);
		img->jcy = ft_atof(av[3]);
	}
	ft_putstr_fd("Controls:\n\t1.WASD move\n\t2.FG zoom\n\t", 1);
	ft_putstr_fd("3.ZX change color\n\t4.1234 change const\n\t", 1);
	ft_putendl_fd("5.ESC or Q to quit program", 1);
}

void	err_ext(t_data *data)
{
	ft_putendl_fd("Set available: \n\t1.Mandlbrot\n\t2.Julia", 1);
	close_all(data);
	exit(1);
}

int	main(int ac, char **av)
{
	t_data		img;

	if (ac > 1)
	{
		img.mlx = mlx_init();
		img.mlx_win = mlx_new_window(img.mlx, WIDTH, HEIGHT, "Fractol");
		img.img = mlx_new_image(img.mlx, WIDTH, HEIGHT);
		img.addr = mlx_get_data_addr(img.img, &img.bpp,
				&img.line_length, &img.endian);
		asign_value(&img, ac, av);
		if (ft_strnstr(av[1], "mandelbrot", 11) && ac == 2)
			put_mandel(&img.img, &img);
		else if (ft_strnstr(av[1], "julia", 6))
			put_julia(&img.img, &img);
		else
			err_ext(&img);
		mlx_put_image_to_window(img.mlx, img.mlx_win, img.img, 0, 0);
		mlx_hook(img.mlx_win, 2, 1L << 0, handle_key, &img);
		mlx_hook(img.mlx_win, 17, 1L << 17, close_all, &img);
		mlx_mouse_hook(img.mlx_win, handle_mouse, &img);
		mlx_loop(img.mlx);
	}
	ft_putendl_fd("Set available: \n\t1.Mandlbrot\n\t2.Julia", 1);
	exit(1);
}

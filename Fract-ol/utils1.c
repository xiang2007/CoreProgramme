/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshou-xi <wshou-xi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 11:23:27 by wshou-xi          #+#    #+#             */
/*   Updated: 2025/09/11 17:02:29 by wshou-xi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fol.h"

void	ftput_pixel(t_data *img_data, int x, int y, int color)
{
	char	*dst;

	dst = img_data->addr + (int)(y * img_data->line_length + x * (img_data->bpp / 8));
	*(unsigned int *)dst = color;
}

static void control(int key, t_data *win)
{
	if (key == XK_a)
		win->x -= 0.01 / win->zoom;
	if (key == XK_d)
		win->x += 0.01 / win->zoom;
	if (key == XK_w)
		win->y -= 0.01 / win->zoom;
	if (key == XK_s)
		win->y += 0.01 / win->zoom;
	put_mandel(&win->img, win);
	mlx_put_image_to_window(win->mlx, win->mlx_win,
								win->img, 0, 0);

}

int	handle_press(int key, t_data *win)
{
	if (key == XK_Escape || key == XK_q)
	{
		mlx_destroy_image(win->mlx, win->img);
		mlx_destroy_window(win->mlx, win->mlx_win);
		mlx_destroy_display(win->mlx);
		free(win->mlx);
		exit(0);
	}
	if (key == XK_f)
	{
		win->zoom += 0.5;
		put_mandel(&win->img, win);
		mlx_put_image_to_window(win->mlx, win->mlx_win,
								win->img, win->x, win->y);
	}
	if (key == XK_w || key == XK_s || key == XK_a || key == XK_d)
		control (key, win);
	return (0);
}


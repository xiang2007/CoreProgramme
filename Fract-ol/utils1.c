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

#include <stdio.h>

static double n_times(double nbr, int n)
{
	while (n)
	{
		nbr /= 10;
		n--;
	}
	return (nbr);
}

double	ft_atof(char *av)
{
	double	res;
	double	temp;
	int		i;
	int		n;
	int		negative;

	res = 0;
	temp = 0;
	i = 2;
	n = 1;
	negative = 1;
	while(av[i])
	{
		if (av[0] == '-')
			negative = -1;
		if (av[i] >= '0' && av[i] <= '9')
		{
			temp = av[i] - '0';
			temp = n_times(temp, n);
			res += temp;
			n++;
		}
		i++;
	}
	return (res * negative);
}

void	change_color(int key, t_data *data)
{
	int	i;

	i = data->color_num;
	if (i < 3 ||i > 6)
	{
		if (i < 3)
			i = 6;
		if (i > 7)
			i = 3;
	}
	if (key == XK_z)
		data->color_num = i++;
	if (key == XK_x)
		data->color_num = i--;
	data->color_num = i;
	if (data->mandel)
		put_mandel(&data->img, data);
	else
		put_julia(&data->img, data);
	mlx_put_image_to_window(data->mlx, data->mlx_win,
							data->img, 0, 0);
}

int	close_all(int key, t_data *data)
{
	if (key > 0)
	{
		mlx_destroy_image(data->mlx, data->img);
		mlx_destroy_window(data->mlx, data->mlx_win);
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		exit(0);
	}
	exit (0);
}

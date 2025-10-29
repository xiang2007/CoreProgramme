/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 11:23:27 by wshou-xi          #+#    #+#             */
/*   Updated: 2025/09/20 01:43:29 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fol.h"

void	ftput_pixel(t_data *img_data, int x, int y, int color)
{
	char	*dst;
	int		temp;

	temp = (int)(y * img_data->line_length + x * (img_data->bpp / 8));
	dst = img_data->addr + temp;
	*(unsigned int *)dst = color;
}

static double	n_times(double nbr, int n)
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
	while (av[i])
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
	if (i < 3 || i > 6)
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

int	close_all(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img);
	mlx_destroy_window(data->mlx, data->mlx_win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(0);
}

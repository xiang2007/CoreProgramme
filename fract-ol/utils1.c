/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshou-xi <wshou-xi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 11:23:27 by wshou-xi          #+#    #+#             */
/*   Updated: 2025/09/10 11:26:26 by wshou-xi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fol.h"

void	ftput_pixel(t_data *img_data, int x, int y, int color)
{
	char	*dst;

	dst = img_data->addr + (int)(y * img_data->line_length + x * (img_data->bpp / 8));
	*(unsigned int *)dst = color;
}

int	close(int keycode, t_data *vars)
{
	mlx_clear_window(vars->mlx, vars->window);
	return (0);
}
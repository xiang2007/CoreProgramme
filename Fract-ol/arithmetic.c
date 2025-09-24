/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arithmetic.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshou-xi <wshou-xi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 16:18:22 by wshou-xi          #+#    #+#             */
/*   Updated: 2025/09/23 16:28:14 by wshou-xi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fol.h"

t_d	d_sq(t_d num)
{
	return (num * num);
}

t_d	get_x_scaled(t_d x, t_d zoom, t_d sx, t_data *data)
{
	if (data->mandel)
		return ((-2 + ((x / (WIDTH - 1)) * 3)) / zoom + sx);
	else
		return ((-2 + (x / (WIDTH - 1)) * 4)/ zoom + sx);
}

t_d	get_y_scaled(t_d y, t_d zoom, t_d sy, t_data *data)
{
	if (data->mandel)
		return ((-1.135 + (y / (HEIGHT - 1)) * 2.27) / zoom + sy);
	else
		return ((-2 + (y / (HEIGHT - 1)) * 4) / zoom + sy);
}

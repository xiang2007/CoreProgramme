/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arithmetic.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshou-xi <wshou-xi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 16:18:22 by wshou-xi          #+#    #+#             */
/*   Updated: 2025/09/09 17:10:11 by wshou-xi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fol.h"

t_d	d_sq(t_d num)
{
	return (num * num);
}

t_d	get_x_scaled(t_d x)
{
	return (XMIN + (x / (WIDTH - 1)) * (XMAX - XMIN));
}

t_d	get_y_scaled(t_d y)
{
	return (YMIN + (y / (HEIGTH - 1)) * (YMAX - YMIN));
}
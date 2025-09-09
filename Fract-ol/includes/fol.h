/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fol.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshou-xi <wshou-xi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 16:18:16 by wshou-xi          #+#    #+#             */
/*   Updated: 2025/09/09 12:04:36 by wshou-xi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FOL_H
# define FOL_H

# define HEIGTH 800
# define WIDTH 800
# define WHITE 0xFFFFFF
# define BLACK 0x000000
# define BLUE 0x003366
# define PURPLE 0x772FB1
# define MAX_ITER 100

typedef double t_d;

typedef struct	s_data
{
	void	*img;
	void	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}				t_data;

typedef struct	s_xy
{
	t_d	x;
	t_d	x0;
	t_d	y;
	t_d	y0;
	t_d	x2;
	t_d	y2;
}				t_xy;

typedef struct s_calc
{
	t_d c;
	t_d z;
	t_d temp;
}				t_calc;

t_d	d_sq(t_d num);
t_d	get_x_scaled(t_d x);
t_d	get_y_scaled(t_d y);

# include "../libft/libft.h"
# include "../mlx_Linux/mlx.h"
# include <stdio.h>
# include <math.h>
# include <unistd.h>

#endif
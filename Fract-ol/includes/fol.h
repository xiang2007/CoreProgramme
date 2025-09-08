/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fol.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 16:18:16 by wshou-xi          #+#    #+#             */
/*   Updated: 2025/09/08 20:28:18 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FOL_H
# define FOL_H

# define HEIGTH 600
# define WIDTH 800
# define WHITE 0xFFFFFFFF
# define BLACK 0x00FF0000
# define MAX_ITER 1000

typedef double t_d;

typedef struct	s_data
{
	void	*img;
	void	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}				t_data;

typedef struct	s_cords
{
	t_d	real_x;
	t_d	img_y;
	t_d	res_c;
	int	iter;
}				t_cords;


# define HEIGTH 600
# define WIDTH 800
# define WHITE 0xFFFFFFFF
# define BLACK 0x00FF0000
# define MAX_ITER 1000

typedef double t_d;

typedef struct	s_data
{
	void	*img;
	void	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}				t_data;

typedef struct	s_cords
{
	t_d	real_x;
	t_d	img_y;
	t_d	res_c;
	int	iter;
}				t_cords;


# include "../libft/libft.h"
# include "../mlx_Linux/mlx.h"
# include <stdio.h>
# include <math.h>
# include <limits.h>

t_d	d_square(t_d num);

#endif
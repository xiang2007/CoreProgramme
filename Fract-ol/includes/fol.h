/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fol.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshou-xi <wshou-xi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 16:18:16 by wshou-xi          #+#    #+#             */
/*   Updated: 2025/09/11 17:29:46 by wshou-xi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FOL_H
# define FOL_H

# define WIDTH 800
# define HEIGTH 800
# define XMIN -2
# define XMAX 1
# define YMIN -1.135
# define YMAX 1.135
# define WHITE 0xFFFFFF
# define BLACK 0x000000
# define RED 0xFF0000
# define ORANGE 0xFF7F00
# define YELLOW 0xFFFF00
# define GREEN 0x00FF00
# define BLUE 0x003366
# define DBLUE 0x00007F
# define PURPLE 0x772FB1
# define MAX_ITER 100

typedef double t_d;

# include "../libft/libft.h"
# include "../mlx_Linux/mlx.h"
# include <stdio.h>
# include <math.h>
# include <unistd.h>
# include <X11/keysym.h>

typedef struct	s_data
{
	void	*img;
	void	*addr;
	void	*mlx; 
	void	*mlx_win;
	int		bpp;
	int		line_length;
	int		endian;
	t_d		zoom;
	t_d		x;
	t_d		y;
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
	t_d	c;
	t_d	z;
	t_d	temp;
}				t_calc;

typedef struct s_color
{
	int	c1;
	int	c2;
	int	color_number;
	int	color;
	int	r1;
	int	r2;
	int	g1;
	int	g2;
	int	b1;
	int	b2;
}				t_color;

typedef struct s_iter
{
	int	i;
	int	j;
	int	iter;
	int	color;
}				t_iter;

typedef struct s_control
{
	t_d	zoom;
	t_d	x;
	t_d	y;
}				t_control;

t_d		d_sq(t_d num);
t_d		get_x_scaled(t_d x, t_d zoom, t_d sx, t_d sy);
t_d		get_y_scaled(t_d y, t_d zoom, t_d sx, t_d sy);
void	ftput_pixel(t_data *img_data, int x, int y, int color);
int		handle_press(int key, t_data *win);
void	put_mandel(void *img, t_data *control);

#endif
#include "fol.h"

static void move(int key, t_data *win)
{
	if (key == XK_Left || key == XK_a)
		win->x -= (0.1) / win->zoom;
	if (key == XK_Right || key == XK_d)
		win->x += (0.1) / win->zoom;
	if (key == XK_Up || key == XK_w)
		win->y -= (0.1) / win->zoom;
	if (key == XK_Down || key == XK_s)
		win->y += (0.1) / win->zoom;
	if (win->mandel)
		put_mandel(&win->img, win);
	else
		put_julia(&win->img, win);
	mlx_put_image_to_window(win->mlx, win->mlx_win,
								win->img, 0, 0);

}

static void zoom(int key, t_data *data)
{
		if (key == XK_f || key == 4)
			data->zoom *= 1.1;
		if ((key == XK_g || key == 5) && data->zoom > 0)
			data->zoom /= 1.1;
		if (data->mandel)
			put_mandel(&data->img, data);
		else
			put_julia(&data->img, data);
		mlx_put_image_to_window(data->mlx, data->mlx_win,
								data->img, 0, 0);
}

int	handle_mouse(int key, int x, int y, t_data *win)
{
	if (key == 4 || key == 5)
	{
		mlx_mouse_get_pos(win->mlx, win->mlx_win, &x, &y);
		if (key == 4)
			win->zoom *= 1.1;
		else if (key == 5)
			win->zoom /= 1.1;
		if (win->mandel)
			put_mandel(&win->img, win);
		else
			put_julia(&win->img, win);
		mlx_put_image_to_window(win->mlx, win->mlx_win,
									win->img, 0, 0);
	}
	return (0);
}

void	change_value(int key, t_data *data)
{
	if (!data->jl)
		return ;
	if (key == XK_1)
	{
		data->jcx *= 1.1;
		data->jcy /= 1.1;
	}
	if (key == XK_2)
	{
		data->jcx /= 1.1;
		data->jcy *= 1.1;
	}
	if (key == XK_3)
	{
		data->jcx += 0.01;
		data->jcy -= 0.01;
	}
	if (key == XK_4)
	{
		data->jcx -= 0.01;
		data->jcy += 0.01;
	}
	put_julia(&data->img, data);
	mlx_put_image_to_window(data->mlx, data->mlx_win,
								data->img, 0, 0);
}

int	handle_key(int key, t_data *win)
{
	if (key == XK_Escape || key == XK_q || key == 17)
	{
		mlx_destroy_image(win->mlx, win->img);
		mlx_destroy_window(win->mlx, win->mlx_win);
		mlx_destroy_display(win->mlx);
		free(win->mlx);
		exit(0);
	}
	if (key == XK_f || key == XK_g)
		zoom(key, win);
	if (key == XK_w || key == XK_s
		|| key == XK_a || key == XK_d
		|| key == XK_Up || key == XK_Down
		|| key == XK_Left || key == XK_Right)
		move (key, win);
	if (key == K1 || key == K2 || key == K3 || key == K4)
		change_value(key, win);
	if (key == XK_z || key == XK_x)
		change_color(key, win);
	return (0);
}

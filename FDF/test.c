#include "libmlx/mlx.h"
#include <math.h>
#include <stdlib.h>

#define WIDTH  800
#define HEIGHT 600
#define WHITE  0xFFFFFF

void	draw_line_dda(void *mlx, void *win, int x1, int y1, int x2, int y2)
{
	float dx = x2 - x1;
	float dy = y2 - y1;
	int steps = fabs(dx) > fabs(dy) ? fabs(dx) : fabs(dy);
	float x_inc = dx / steps;
	float y_inc = dy / steps;
	float x = x1;
	float y = y1;

	for (int i = 0; i <= steps; i++)
	{
		mlx_pixel_put(mlx, win, round(x), round(y), WHITE);
		x += x_inc;
		y += y_inc;
	}
}

int	main(void)
{
	void *mlx;
	void *win;

	mlx = mlx_init();
	win = mlx_new_window(mlx, WIDTH, HEIGHT, "DDA Line - MiniLibX");

	// Example line: from (100, 100) to (600, 400)
	draw_line_dda(mlx, win, 100, 100, 600, 400);

	mlx_loop(mlx);
	return (0);
}

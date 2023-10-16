#include "fractol.h"
#include <stdio.h>

int	close_press(t_fractal	*fractol)
{
	mlx_destroy_image(fractol->mlx, fractol->img.img);
	mlx_destroy_window(fractol->mlx, fractol->win);
	free( fractol->mlx);
	exit(EXIT_SUCCESS);
}

int mouse_press(int keycode,int x, int y, t_fractal  *fractol)
{
	if (keycode == MOUSE_UP)
	{
		fractol->zoom *= 0.90;
	}
	else if (keycode == MOUSE_DOWN)
	{
		fractol->zoom *= 1.10;
	}
	fractal_draw(fractol);
	return 0;
}

int	key_press(int keycode, t_fractal *fractol)
{
	if (keycode == ESC_KEY)
	{
		close_press(fractol);
	}
	else if (keycode == LEFT_KEY)
		fractol->shift_x += 0.5;
	else if (keycode == RIGHT_KEY)
		fractol->shift_x -= 0.5;
	else if (keycode == UP_KEY)
		fractol->shift_y -= 0.5;
	else if (keycode == DOWN_KEY)
		fractol->shift_y += 0.5;
	else if (keycode == PLUS_KEY)
		fractol->iteration += 10;
	else if (keycode == MINUS_KEY)
		fractol->iteration -= 10;
	fractal_draw(fractol);
	return (0);
}

int	julia_track(int x, int y, t_fractal *fractal)
{
	if (!ft_strcmp(fractal->name, "julia"))
	{
		fractal->julia_x = (scale(x, -2, +2, 0, WIDTH) * fractal->zoom) + fractal->shift_x;
		fractal->julia_y = (scale(y, +2, -2, 0, HEIGHT) * fractal->zoom) + fractal->shift_y;
		fractal_draw(fractal);
	}
	return 0;
}

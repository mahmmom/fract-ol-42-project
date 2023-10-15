#include "fractol.h"

int	close_press(t_fractal	*fractol)
{
	mlx_destroy_image(fractol->mlx, fractol->img.img);
	mlx_destroy_window(fractol->mlx, fractol->win);
	free( fractol->mlx);
	exit(EXIT_SUCCESS);
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
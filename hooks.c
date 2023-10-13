#include "fractol.h"

int	close_handler(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx,
					fractal->img.addr);
	mlx_destroy_window(fractal->mlx,
						fractal->win);
	mlx_destroy_display(fractal->mlx);
	free(fractal->mlx);
	exit(EXIT_SUCCESS);
}

int	key_handler(int keysym, t_fractal *fractal)
{
	if (keysym == )
		close_handler(fractal);
	if (keysym == )
		fractal->shift_x += (0.5 * fractal->zoom);	
	else if (keysym == )
		fractal->shift_x -= (0.5 * fractal->zoom);	
	else if (keysym == )
		fractal->shift_y -= (0.5 * fractal->zoom);	
	else if (keysym == )
		fractal->shift_y += (0.5 * fractal->zoom);	
	else if (keysym == )
		fractal->iteration += 10;
	else if (keysym == )	
		fractal->iteration -= 10;
	fractal_draw(fractal);
	return 0;
}

int	mouse_handler(int button, int x, int y, t_fractal *fractal)
{
	if (button == )
	{
		fractal->zoom *= 0.95;
	}
	else if (button == )
	{
		fractal->zoom *= 1.05;
	}
	fractal_draw(fractal);
	return 0;
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

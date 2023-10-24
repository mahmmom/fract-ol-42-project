#include "mlx.h"
#include <math.h>

#define WIDTH 800
#define HEIGHT 600

typedef struct s_complex
{
	double real;
	double imag;
} t_complex;

typedef struct s_fractal
{
	void *mlx_ptr;
	void *win_ptr;
	int max_iter;
	double zoom;
	double x_offset;
	double y_offset;
} t_fractal;

int burning_ship(t_complex c, int max_iter)
{
	t_complex z;
	int i;

	z.real = 0.0;
	z.imag = 0.0;
	i = 0;
	while (i < max_iter)
	{
		double r2 = z.real * z.real;
		double i2 = z.imag * z.imag;

		if (r2 + i2 > 4.0)
			return i;

		z.imag = 2.0 * fabs(z.real * z.imag) + c.imag;
		z.real = r2 - i2 + c.real;
		i++;
	}
	return max_iter;
}

void draw_burning_ship(t_fractal *fractal)
{
	int x;
	int y;
	t_complex c;
	int color;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			c.real = (x - WIDTH / 2) / (0.5 * WIDTH * fractal->zoom) + fractal->x_offset;
			c.imag = (y - HEIGHT / 2) / (0.5 * HEIGHT * fractal->zoom) + fractal->y_offset;
			color = burning_ship(c, fractal->max_iter);

			// Color mapping based on 'color'
			unsigned char r = (color % 8) * 32;
			unsigned char g = (color % 16) * 16;
			unsigned char b = (color % 32) * 8;

			int rgb = (r << 16) | (g << 8) | b;
			mlx_pixel_put(fractal->mlx_ptr, fractal->win_ptr, x, y, rgb);
			x++;
		}
		y++;
	}
}

int handle_key(int key, t_fractal *fractal)
{
	if (key == 53) // ESC key
		exit(0);
	else if (key == 69 || key == 78) // '+' and '-' keys for zoom
	{
		fractal->zoom *= (key == 69) ? 1.1 : 0.9;
	}
	else if (key == 123 || key == 124 || key == 125 || key == 126) // Arrow keys for movement
	{
		double move_step = 0.1 / fractal->zoom;
		if (key == 123) // Left
			fractal->x_offset -= move_step;
		else if (key == 124) // Right
			fractal->x_offset += move_step;
		else if (key == 125) // Down
			fractal->y_offset += move_step;
		else if (key == 126) // Up
			fractal->y_offset -= move_step;
	}
	else if (key == 46 || key == 47) // ',' and '.' keys for changing iterations
	{
		fractal->max_iter += (key == 46) ? -10 : 10;
		if (fractal->max_iter < 10)
			fractal->max_iter = 10;
	}

	draw_burning_ship(fractal);
	mlx_put_image_to_window(fractal->mlx_ptr, fractal->win_ptr, mlx_new_image(fractal->mlx_ptr, WIDTH, HEIGHT), 0, 0);
	return (0);
}

int main()
{
	t_fractal fractal;

	fractal.mlx_ptr = mlx_init();
	fractal.win_ptr = mlx_new_window(fractal.mlx_ptr, WIDTH, HEIGHT, "Burning Ship Fractal");
	fractal.max_iter = 100; // You can adjust the number of iterations for more detail
	fractal.zoom = 1.0;
	fractal.x_offset = 0.0;
	fractal.y_offset = 0.0;

	draw_burning_ship(&fractal);
	mlx_key_hook(fractal.win_ptr, handle_key, &fractal);
	mlx_loop(fractal.mlx_ptr);

	return (0);
}

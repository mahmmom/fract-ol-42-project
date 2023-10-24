#include "mlx.h"

#define WIDTH 800
#define HEIGHT 600

typedef struct s_complex
{
	double	real;
	double	imag;
} t_complex;

int	burning_ship(t_complex c, int max_iter)
{
	t_complex	z;
	int			i;

	z.real = 0.0;
	z.imag = 0.0;
	i = 0;
	while (i < max_iter)
	{
		double r2 = z.real * z.real;
		double i2 = z.imag * z.imag;

		if (r2 + i2 > 4.0)
			return (i);

		z.imag = 2.0 * fabs(z.real * z.imag) + c.imag;
		z.real = r2 - i2 + c.real;
		i++;
	}
	return (max_iter);
}

void draw_burning_ship(void *mlx_ptr, void *win_ptr, int max_iter)
{
	int			x;
	int			y;
	t_complex	c;
	int			color;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			c.real = 1.5 * (x - WIDTH / 2) / (0.5 * WIDTH);
			c.imag = (y - HEIGHT / 2) / (0.5 * HEIGHT);
			color = burning_ship(c, max_iter);
			mlx_pixel_put(mlx_ptr, win_ptr, x, y, color);
			x++;
		}
		y++;
	}
}

int main()
{
	void *mlx_ptr;
	void *win_ptr;
	int max_iter;

	max_iter = 100; // You can adjust the number of iterations for more detail
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, WIDTH, HEIGHT, "Burning Ship Fractal");
	draw_burning_ship(mlx_ptr, win_ptr, max_iter);
	mlx_loop(mlx_ptr);
	return (0);
}

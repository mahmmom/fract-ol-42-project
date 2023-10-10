#include "fractol.h"
#include "minilibx_macos/mlx.h"

void	ft_kickoff(t_fractal *fractol)
{
	fractol->mlx = mlx_init();
	fractol->win = mlx_new_window(fractol->mlx, HEIGHT, WIDTH, "fractol");
	fractol->img = mlx_new_image(fractol->mlx, HEIGHT, WIDTH);
	fractol->addr = mlx_get_data_addr(fractol->img, &fractol->bits_per_pixel, 
		&fractol->line_length, &fractol->endian);
	fractol->x = 0;
 	fractol->y = 0;
	fractol->zoom_factor = 1.5;
    while (fractol->y < HEIGHT)
    {
        fractol->x = 0;
        while (fractol->x < WIDTH)
        {
            double real = ((fractol->x - WIDTH / 2.0) * 4.0 / WIDTH) / fractol->zoom_factor;
            double imag = ((fractol->y - HEIGHT / 2.0) * 4.0 / HEIGHT) / fractol->zoom_factor;

            mlx_pixel_put(fractol->mlx, fractol->win, 
				fractol->x, fractol->y, 0x00010101);
            fractol->x++;
        }
        fractol->y++;
    }
	//mlx_key_hook(fractol->win, keyhook, &fractol);
	mlx_loop(fractol->mlx);
}
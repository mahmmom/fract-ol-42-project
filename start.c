#include "fractol.h"
#include "minilibx-linux/mlx.h"

static void    malloc_error(void)
{
    perror("Error in malloc allocation");
    exit(EXIT_FAILURE);
}

void    data_init(t_fractal *fractol)
{
    fractol->outer_value = 4;
    fractol->iteration = 42;
}

void    event_start(t_fractal   *fractol)
{
   
}

void	start_fractol(t_fractal *fractol)
{
	fractol->mlx = mlx_init();
    if (!fractol->mlx)
        malloc_error();
	fractol->win = mlx_new_window(fractol->mlx, HEIGHT, WIDTH, fractol->name);
    if (!fractol->win)
    {
        mlx_destroy_display(fractol->mlx);
        free(fractol->win);
        malloc_error();
    }
	fractol->img.img = mlx_new_image(fractol->mlx, HEIGHT, WIDTH);
    if (!fractol->img.img)
    {
        mlx_destroy_window(fractol->mlx, fractol->win);
        mlx_destroy_display(fractol->mlx);
        free(fractol->win);
        malloc_error();
    }
	fractol->img.addr = mlx_get_data_addr(fractol->img.img, &fractol->img.bits_per_pixel, 
		&fractol->img.line_length, &fractol->img.endian);
	
	event_start(fractol);
    //data_start(fractol);
}

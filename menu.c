#include "fractol.h"

static void display_menu(void *mlx_ptr, void *win_ptr)
{
    mlx_string_put(mlx_ptr, win_ptr, WIDTH, 400, 0xFFFFFF, "Option 1");
    mlx_string_put(mlx_ptr, win_ptr, WIDTH, 450, 0xFFFFFF, "Option 2");
}

void toggle_menu(t_fractal *fractol)
{
    if (fractol->visib)
	{
        mlx_put_image_to_window(fractol->mlx, fractol->win, fractol->img.addr, 0, 0);
        fractol->visib = 0;
    } else
	{
        display_menu(fractol->mlx, fractol->win);
        fractol->visib = 1;
    }
}
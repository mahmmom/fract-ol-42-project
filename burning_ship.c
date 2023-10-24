#include "fractol.h"

static int burning_ship(t_complex c, t_fractal *fractol)
{
    t_complex z;
    int i;
	double z_x_squared;
    double z_y_squared;

    z.x = 0.0;
    z.y = 0.0;
    i = 0;
    while (i < fractol->iteration)
    {
        z_x_squared = z.x * z.x;
        z_y_squared = z.y * z.y;
        if (z_x_squared + z_y_squared > 4.0)
            return (i);
        z.y = 2.0 * fabs(z.x * z.y) + c.y;
        z.x = z_x_squared - z_y_squared + c.x;
        i++;
    }
    return fractol->iteration;
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
            c.x = (x - WIDTH / 2) / (0.5 * WIDTH * fractal->zoom) + fractal->shift_x;
            c.y = (y - HEIGHT / 2) / (0.5 * HEIGHT * fractal->zoom) + fractal->shift_y;
            color = burning_ship(c, fractal);

            if (color == fractal->iteration)
                my_pixel_put(x, y, &fractal->img, BLACK);
            else
                my_pixel_put(x, y, &fractal->img, color * fractal->iteration);
            x++;
        }
        y++;
    }
    mlx_put_image_to_window(fractal->mlx, fractal->win, fractal->img.img, 0, 0);
}

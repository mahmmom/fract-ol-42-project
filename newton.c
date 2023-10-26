#include "fractol.h"

static int newton_fractal(t_complex z, int max_iter)
{
    t_complex   numerator;
    t_complex   denominator;
    t_complex   derivative;
    int         i;

    while (i < max_iter)
    {
        double z_squared = z.x * z.x + z.y * z.y;
        if (z_squared < 1e-6)
            return (i);
        // Define your polynomial and its derivative here
        // Example: z^3 - 1
        numerator.x = z.x * z.x * z.x - 3.0 * z.x * z.y * z.y - 1.0;
        numerator.y = 3.0 * z.x * z.x * z.y - z.y * z.y * z.y;
        denominator.x = 3.0 * z.x * z.x - 3.0 * z.y * z.y;
        denominator.y = 6.0 * z.x * z.y;
        derivative.x = numerator.x / denominator.x;
        derivative.y = numerator.y / denominator.x;
        z.x -= derivative.x;
        z.y -= derivative.y;
        i++;
    }
    return (max_iter);
}

void draw_newton_fractal(t_fractal *fractol)
{
    int x;
    int y;
    int color;
    t_complex c;

    y = 0;
    while (y < HEIGHT)
    {
        x = 0;
        while (x < WIDTH)
        {
            c.x = (x - WIDTH / 2) / (0.5 * WIDTH * fractol->zoom) + fractol->shift_x;
            c.y = (y - HEIGHT / 2) / (0.5 * HEIGHT * fractol->zoom) + fractol->shift_y;
            color = newton_fractal(c, fractol->);

            if (color == fractol->iteration)
                my_pixel_put(x, y, &fractol->img, BLACK);
            else
                my_pixel_put(x, y, &fractol->img, color * fractol->iteration);
            x++;
        }
        y++;
    }
    mlx_put_image_to_window(fractol->mlx, fractol->win, fractol->img.img, 0, 0);
}

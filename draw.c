#include "fractol.h"

static void	my_pixel_put(int x, int y, t_img *img, int color)
{
	int	offset;

	offset = (y * img->line_length) + (x * (img->bits_per_pixel / 8));
	*(unsigned int *)(img->addr + offset) = color;
}

void    pixel_handel(int x, int y, t_fractal *fractol)
{
    t_complex   z;
    t_complex   c;

    z.x = 0.0;
    z.y = 0.0;
    c.x = scale(x, -2, +2, 0, HEIGHT);
    c.y = scale(y, +2, -2, 0, WIDTH);
    while (??)
    {
        z = sum_complex(square_complex(z), c);
        if ((z.x * z.x) + (z.y * z.y) < fractol->outer_value)
        {
        my_pixel_put();
        return;
        }
    }
}

void    fractal_draw(t_fractal *fractol)
{
    int x;
    int y;

    y = 0;
    while (y < HEIGHT)
    {
        x = 0;
        while (x < WIDTH)
        {
            pixel_handel(x,y,fractol);
            x++;
        }
        y++;
    }
}

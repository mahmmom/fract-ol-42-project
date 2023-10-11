#include "fractol.h"

void    pixel_handel(int x, int y, t_fractal *fractol)
{
    t_complex   z;
    t_complex   c;

    z.x = 0.0;
    z.y = 0.0;
    c.x = scale(x, -2, +2, 0, HEIGHT);
    c.y = scale(y, +2, -2, 0, WIDTH);
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

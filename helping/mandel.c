#include "minilibx/mlx.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct s_data
{
    void *mlx;
    void *win;
    int zoom_factor;
    void *img;
    char *addr;
    int bits_per_pixel;
    int line_length;
    int endian;
} t_data;

#define WIDTH 1920
#define HEIGHT 1080
#define MAX_ITER 80

#define ESC_KEY 53
#define PLUS_KEY 24
#define MINUS_KEY 27

void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int *)dst = color;
}
int mandelbrot(double x, double y)
{
    int i = 0;
    double real = x;
    double imag = y;

    while (i < MAX_ITER)
    {
        double real2 = real * real;
        double imag2 = imag * imag;
        if (real2 + imag2 > 4.0)
            return (i);
        imag = 2 * real * imag + y;
        real = real2 - imag2 + x;
        i++;
    }

    return (MAX_ITER);
}

int key_hook(int keycode, t_data *data)
{
    if (keycode == ESC_KEY)
    {
        mlx_destroy_window(data->mlx, data->win);
        exit(0);
    }
    else if (keycode == PLUS_KEY)
    {
        data->zoom_factor *= 2; // Zoom in by doubling the zoom factor
    }
    else if (keycode == MINUS_KEY)
    {
        // Zoom out by halving the zoom factor, but ensure it doesn't go below 1
        if (data->zoom_factor > 1)
        {
            data->zoom_factor /= 2;
        }
    }

    // Clear the window and redraw the Mandelbrot fractal
    mlx_clear_window(data->mlx, data->win);
    int x = 0;
    int y = 0;
    while (y < HEIGHT)
    {
        x = 0;
        while (x < WIDTH)
        {
            double real = ((x - WIDTH / 2.0) * 4.0 / WIDTH) / data->zoom_factor;
            double imag = ((y - HEIGHT / 2.0) * 4.0 / HEIGHT) / data->zoom_factor;
            int color = mandelbrot(real, imag);

            mlx_pixel_put(data->mlx, data->win, x, y, color | 0x00010101);
            x++;
        }
        y++;
    }
    return (0);
}

int main()
{
    t_data data;

    data.zoom_factor = 1;
    data.mlx = mlx_init();
    data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "Mandelbrot Fractal");

    mlx_key_hook(data.win, key_hook, &data);

    int x = 0;
    int y = 0;
    while (y < HEIGHT)
    {
        x = 0;
        while (x < WIDTH)
        {
            double real = ((x - WIDTH / 2.0) * 4.0 / WIDTH) / data.zoom_factor;
            double imag = ((y - HEIGHT / 2.0) * 4.0 / HEIGHT) / data.zoom_factor;
            int color = mandelbrot(real, imag);
            mlx_pixel_put(data.mlx, data.win, x, y, color * 0x00010101);
            x++;
        }
        y++;
    }

    mlx_loop(data.mlx);
    return (0);
}

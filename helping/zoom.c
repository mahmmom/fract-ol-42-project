#include "./minilibx/mlx.h"
#include <stdio.h>
#include <stdlib.h>

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

void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int *)dst = color;
}

#define ESC_KEY 53
#define PLUS_KEY 24
#define MINUS_KEY 27

void draw_shape(t_data *data)
{
    mlx_clear_window(data->mlx, data->win);

    int size = 50 + data->zoom_factor * 10;
    int x = 400;
    int y = 300;

    mlx_string_put(data->mlx, data->win, 10, 10, 0xFFFFFF, "Press + or - to zoom");

    int i = x - size / 2;
    while (i <= x + size / 2)
    {
        int j = y - size / 2;
        while (j <= y + size / 2)
        {
            my_mlx_pixel_put(data, i, j, 0x00FF0000);
            j++;
        }
        i++;
    }
    mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
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
        data->zoom_factor++;
        draw_shape(data);
    }
    else if (keycode == MINUS_KEY)
    {
        data->zoom_factor--;
        draw_shape(data);
    }

    return (0);
}

int main(void)
{
    t_data data;

    data.zoom_factor = 0;
    data.mlx = mlx_init();
    data.win = mlx_new_window(data.mlx, 800, 600, "MiniLibX Zoom Example");

    data.img = mlx_new_image(data.mlx, 800, 600);

    data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.line_length, &data.endian);

    mlx_key_hook(data.win, key_hook, &data);

    draw_shape(&data);

    mlx_loop(data.mlx);

    return (0);
}

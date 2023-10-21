/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohamoha <mohamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 18:34:38 by mohamoha          #+#    #+#             */
/*   Updated: 2023/10/21 21:13:51 by mohamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	my_pixel_put(int x, int y, t_img *img, int color)
{
	int	offset;

	offset = (y * img->line_length) + (x * (img->bits_per_pixel / 8));
	*(unsigned int *)(img->addr + offset) = color;
}
double	scale_burning(double s, double max2, double min1, double max1)
{
	return ((s - min1) * (max2 - 0) / (max1 - min1) + 0);
}

static void    pixel_handel_burning_ship(int x, int y, t_fractal *fractol)
{
    t_complex   z;
    t_complex   c;
    int         i;
    int         color;

    i = 0;
    z.x = 0;
    z.y = 0;
    c.x = (scale(x, WIDTH, -2, 2) * fractol->zoom) + fractol->shift_x;
    c.y = (scale(y, HEIGHT, -2, 2) * fractol->zoom) + fractol->shift_y;

    while (i < fractol->iteration && (z.x * z.x + z.y * z.y) < fractol->outer_value)
    {
        double xtemp = z.x * z.x - z.y * z.y + c.x;
        z.y = fabs(2 * z.x * z.y) + c.y;
        z.x = fabs(xtemp);
        i++;
    }

    color = scale(i, BLACK, WHITE, fractol->iteration);
    my_pixel_put(x, y, &fractol->img, color);
}

void    fractal_draw_burning_ship(t_fractal *fractol)
{
    int x;
    int y;

    y = 0;
    while (y < HEIGHT)
    {
        x = 0;
        while (x < WIDTH)
        {
            pixel_handel_burning_ship(x, y, fractol);
            x++;
        }
        y++;
    }
    mlx_put_image_to_window(fractol->mlx, fractol->win, fractol->img.img, 0, 0);
}

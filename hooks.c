/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohamoha <mohamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 19:34:02 by mohamoha          #+#    #+#             */
/*   Updated: 2023/10/24 20:01:02 by mohamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_press(t_fractal *fractol)
{
	mlx_destroy_image(fractol->mlx, fractol->img.img);
	mlx_destroy_window(fractol->mlx, fractol->win);
	free(fractol->mlx);
	exit(EXIT_SUCCESS);
}

int	mouse_press(int keycode, int x, int y, t_fractal *fractol)
{
	(void)x;
	(void)y;
	if (keycode == MOUSE_UP)
	{
		fractol->zoom *= 0.70;
	}
	else if (keycode == MOUSE_DOWN)
	{
		fractol->zoom *= 1.80;
	}
	if (!ft_strcmp(fractol->name, "mandelbrot")
		|| !ft_strcmp(fractol->name, "julia"))
	{
		fractal_draw(fractol);
	}
	else if (!ft_strcmp(fractol->name, "burning_ship"))
	{
		draw_burning_ship(fractol);
	}
	return (0);
}

int	key_press(int keycode, t_fractal *fractol)
{
	if (keycode == ESC_KEY)
		close_press(fractol);
	else if (keycode == LEFT_KEY)
		fractol->shift_x += 0.5;
	else if (keycode == RIGHT_KEY)
		fractol->shift_x -= 0.5;
	else if (keycode == UP_KEY)
		fractol->shift_y -= 0.5;
	else if (keycode == DOWN_KEY)
		fractol->shift_y += 0.5;
	else if (keycode == PLUS_KEY)
		fractol->iteration += 5;
	else if (keycode == MINUS_KEY)
		fractol->iteration -= 5;
	if (!ft_strcmp(fractol->name, "mandelbrot")
		|| !ft_strcmp(fractol->name, "julia"))
	{
		fractal_draw(fractol);
	}
	else if (!ft_strcmp(fractol->name, "burning_ship"))
	{
		draw_burning_ship(fractol);
	}
	return (0);
}

int	julia_track(int x, int y, t_fractal *fractal)
{
	if (!ft_strcmp(fractal->name, "julia"))
	{
		if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
		{
			fractal->julia_x = (scale(x, -2, +2, WIDTH) * fractal->zoom)
				+ fractal->shift_x;
			fractal->julia_y = (scale(y, +2, -2, HEIGHT) * fractal->zoom)
				+ fractal->shift_y;
			fractal_draw(fractal);
		}
	}
	return (0);
}

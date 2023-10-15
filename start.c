/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohamoha <mohamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 18:35:25 by mohamoha          #+#    #+#             */
/*   Updated: 2023/10/15 21:22:02 by mohamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "minilibx/mlx.h"

static void    malloc_error(void)
{
    perror("Error in malloc allocation");
    exit(EXIT_FAILURE);
}

static void    data_init(t_fractal *fractol)
{
    fractol->outer_value = 4;
    fractol->iteration = 40;
    fractol->shift_x = 0.0;
    fractol->shift_y = 0.0;
    fractol->zoom = 1.0;
}
static void	key_hook(t_fractal *fractol)
{
	mlx_hook(fractol->win, 2, 1L<<0, key_press, fractol);
	//mlx_hook(fractol->win, 4, 1L<<2, mouse_press, fractol);
	mlx_hook(fractol->win, 17, 1L<<17, close_press, fractol);
}
void	start_fractol(t_fractal *fractol)
{
	fractol->mlx = mlx_init();
    if (!fractol->mlx)
	{
		malloc_error();
	}
	fractol->win = mlx_new_window(fractol->mlx, 
		WIDTH, HEIGHT, fractol->name);
    if (!fractol->win)
    {
        free(fractol->win);
        malloc_error();
    }
	fractol->img.img = mlx_new_image(fractol->mlx, WIDTH, HEIGHT);
    if (!fractol->img.img)
    {
        mlx_destroy_window(fractol->mlx, fractol->win);
        free(fractol->win);
        malloc_error();
    }
	fractol->img.addr = mlx_get_data_addr(fractol->img.img, &fractol->img.bits_per_pixel, 
		&fractol->img.line_length, &fractol->img.endian);
	key_hook(fractol);
    data_init(fractol);
}
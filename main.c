/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohamoha <mohamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 18:52:03 by mohamoha          #+#    #+#             */
/*   Updated: 2023/10/15 19:55:11 by mohamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int ac, char **av)
{
	t_fractal   fractol;

	if ((ac == 2 && !ft_strcmp(av[1], "mandelbrot"))
		|| (ac == 4 && !ft_strcmp(av[1], "julia")))
	{
		fractol.name = av[1];
		if (!ft_strcmp(fractol.name, "julia"))
		{
			fractol.julia_x = atoi_dbl(av[2]);
			fractol.julia_y = atoi_dbl(av[3]);
		}
		start_fractol(&fractol);
		fractal_draw(&fractol);
		mlx_loop(fractol.mlx);
	}
	else
	{
		putstr_fd(ERROR_MESSAGE, STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
}
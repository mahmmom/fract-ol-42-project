/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohamoha <mohamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 18:52:03 by mohamoha          #+#    #+#             */
/*   Updated: 2023/10/24 18:32:21 by mohamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int ac, char **av)
{
	t_fractal	fractol;

	if ((ac == 2 && !ft_strcmp(av[1], "mandel"))
		|| (ac == 4 && !ft_strcmp(av[1], "julia")))
	{
		fractol.name = av[1];
		if (!ft_strcmp(av[1], "julia"))
		{
			fractol.name = av[1];
			fractol.julia_x = atoi_dbl(av[2]);
			fractol.julia_y = atoi_dbl(av[3]);
		}
		start_fractol(&fractol);
		fractal_draw(&fractol);
		mlx_loop(fractol.mlx);
	}
	else if (ac == 2 && !ft_strcmp(av[1], "burning_ship"))
	{
		fractol.name = av[1];
		start_fractol(&fractol);
		draw_burning_ship(&fractol);
		mlx_loop(fractol.mlx);
	}
	else
	{
		putstr_fd(ERROR_MESSAGE, STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
}

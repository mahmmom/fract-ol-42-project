/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohamoha <mohamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 18:52:03 by mohamoha          #+#    #+#             */
/*   Updated: 2023/10/10 21:04:00 by mohamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "./minilibx_macos/mlx.h"

int	main(int ac, char **av)
{
	t_fractal	*fractol;

	if ((ac == 2 && !ft_strcmp(av[1], "mandelbrot"))
		|| (ac == 4 && !ft_strcmp(av[1], "julia")))
	{
		printf("its working\n");
		ft_kickoff(fractol);
	}
	else
	{
		printf("ERROR 404\n");
		exit(EXIT_FAILURE);
	}
}

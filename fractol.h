/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohamoha <mohamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 18:51:51 by mohamoha          #+#    #+#             */
/*   Updated: 2023/10/10 21:19:45 by mohamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <math.h>
# include "./minilibx-linux/mlx.h"

#define ERROR_MESSAGE "Invalid entry!!! Kindly enter \n\t\"./fractol mandelbrot\" or \n\t\"./fractol julia <val1> <val2>\"\n"

# define HEIGHT 800
# define WIDTH 800
# define MAX_ITER 50

#define COLOR_BLACK 0x000000
#define COLOR_WHITE 0xFFFFFF
#define COLOR_ORANGE 0xFFA500
#define COLOR_PURPLE 0x800080 

typedef struct s_complex {
    double  x;
    double  y;
} t_complex;

typedef struct s_img {
    void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
} t_img;

typedef struct s_fractal {
	void	*mlx;
	void	*win;
	char	*name;
	t_img	img;
	double  outer_value;
}	t_fractal;

int		ft_strcmp(char *s1, char *s2);
void    putstr_fd(char *s, int fd);

t_complex   sum_complex(t_complex z1, t_complex z2);
t_complex   square_complex(t_complex z);

void	start_fractol(t_fractal *fractol);
void    fractal_draw(t_fractal *fractol);

double  scale(double s, double min2, double max2, double min1, double max1);

void	mandelbrot(t_fractal	*fractol);

#endif

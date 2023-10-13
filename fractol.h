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

#define BLACK 0x000000
#define WHITE 0xFFFFFF
#define ORANGE 0xFFA500
#define PURPLE 0x800080 

#define SKY_BLUE    0x87CEEB
#define LAVENDER    0xE6E6FA
#define CHOCOLATE   0xD2691E
#define LIME_GREEN  0x32CD32
#define TURQUOISE   0x40E0D0
#define TEAL        0x008080
#define MAROON      0x800000

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
    int     iteration;
    double  shift_x;
    double  shift_y;
    double  zoom;
    double	julia_x;
	double	julia_y;
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

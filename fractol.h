/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohamoha <mohamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 18:51:51 by mohamoha          #+#    #+#             */
/*   Updated: 2023/10/24 19:44:36 by mohamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "minilibx/mlx.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define ERROR_MESSAGE "Enter \n\t\"mandel\" \n\t\"julia <1> <2>\" \n\t\"burning_ship\"\n"

# define HEIGHT 800
# define WIDTH 800

# define BLACK 0x000000
# define WHITE 0xFFFFFF
# define ORANGE 0xFFA500
# define PURPLE 0x800080

# define SKY_BLUE 0x87CEEB
# define LAVENDER 0xE6E6FA
# define CHOCOLATE 0xD2691E
# define LIME_GREEN 0x32CD32
# define TURQUOISE 0x40E0D0
# define TEAL 0x008080
# define MAROON 0x800000

# define ESC_KEY 53
# define PLUS_KEY 69
# define MINUS_KEY 78
# define RIGHT_KEY 124
# define LEFT_KEY 123
# define UP_KEY 126
# define R_KEY 44 NEED TO FIX
# define DOWN_KEY 125
# define MENU_KEY 46
# define MOUSE_UP 5
# define MOUSE_DOWN 4

typedef struct s_complex
{
	double		x;
	double		y;
}				t_complex;

typedef struct s_img
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_img;

typedef struct s_fractal
{
	t_img		img;
	void		*mlx;
	void		*win;
	char		*name;
	double		outer_value;
	int			iteration;
	double		shift_x;
	double		shift_y;
	double		zoom;
	double		julia_x;
	double		julia_y;
	int		visib;
	int		pow;
}				t_fractal;


int			ft_strcmp(char *s1, char *s2);
void			putstr_fd(char *s, int fd);
double			atoi_dbl(char *s);

t_complex		sum_complex(t_complex z1, t_complex z2);
t_complex		square_complex(t_complex z);
double			scale(double s, double min2, double max2, double max1);

void			my_pixel_put(int x, int y, t_img *img, int color);
void			start_fractol(t_fractal *fractol);
void			fractal_draw(t_fractal *fractol);
void 			draw_burning_ship(t_fractal *fractal);

int				key_press(int keysym, t_fractal *fractol);
int				close_press(t_fractal *fractol);
int				mouse_press(int keycode, int x, int y, t_fractal *fractol);
int				julia_track(int x, int y, t_fractal *fractol);
void			toggle_menu(t_fractal *fractol);

#endif

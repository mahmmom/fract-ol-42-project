#include "minilibx/mlx.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct	s_vars {
	void	*mlx;
	void	*win;
	int		width;
	int		height;
}				t_vars;

int	close(int keycode, t_vars *vars)
{
	printf("%d\n", keycode);
	if (keycode == 53)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	return (0);
}

int	resize(int keycode, t_vars *vars)
{
	if (keycode == 24) // Keycode for '=' (Zoom in)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		vars->width *= 2;
		vars->height *= 2;
		vars->win = mlx_new_window(vars->mlx, vars->width, vars->height, "Resized Window");
		mlx_hook(vars->win, 2, 1L << 0, close, vars);
		mlx_key_hook(vars->win, resize, vars);
	}
	else if (keycode == 27) // Keycode for '-' (Zoom out)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		vars->width /= 2;
		vars->height /= 2;
		vars->win = mlx_new_window(vars->mlx, vars->width, vars->height, "Resized Window");
		mlx_hook(vars->win, 2, 1L << 0, close, vars);
		mlx_key_hook(vars->win, resize, vars);
	}
	return (0);
}

int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.width = 800;
	vars.height = 800;
	vars.win = mlx_new_window(vars.mlx, vars.width, vars.height, "Resizable Window");
	mlx_hook(vars.win, 2, 1L << 0, close, &vars);
	mlx_key_hook(vars.win, resize, &vars);
	mlx_loop(vars.mlx);
}

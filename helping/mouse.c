#include "minilibx/mlx.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct s_vars {
    void    *mlx;
    void    *win;
    int     width;
    int     height;
    int     last_x; // Store the last known x-coordinate
    int     last_y; // Store the last known y-coordinate
}           t_vars;

int close(int keycode, t_vars *vars)
{
    printf("%d\n", keycode);
    if (keycode == 53)
    {
        mlx_destroy_window(vars->mlx, vars->win);
        exit(0);
    }
    return (0);
}

int mouse_scroll(int button, int x, int y, t_vars *vars)
{
    // Access the last known x and y coordinates
    int last_x = vars->last_x;
    int last_y = vars->last_y;

    printf("Mouse scroll event at x: %d, y: %d\n", last_x, last_y);
	
	// button == 4 indicates scrolling down (zoom in)
    if (button == 5)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		vars->width *= 2;
		vars->height *= 2;
		vars->win = mlx_new_window(vars->mlx, vars->width, vars->height, "Zoomed In Window");
		mlx_hook(vars->win, 2, 1L << 0, close, vars);
		mlx_mouse_hook(vars->win, mouse_scroll, vars);
	}

	// button == 5 indicates scrolling down (zoom out)
	if (button == 4)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		vars->width /= 2;
		vars->height /= 2;
		vars->win = mlx_new_window(vars->mlx, vars->width, vars->height, "Zoomed Out Window");
		mlx_hook(vars->win, 2, 1L << 0, close, vars);
		mlx_mouse_hook(vars->win, mouse_scroll, vars);
	}

    // Update the last known x and y coordinates
    vars->last_x = x;
    vars->last_y = y;

    return (0);
}

int main(void)
{
    t_vars vars;

    vars.mlx = mlx_init();
    vars.width = 800;
    vars.height = 800;
    vars.win = mlx_new_window(vars.mlx, vars.width, vars.height, "Zoomable Window");
    vars.last_x = 0; // Initialize last_x
    vars.last_y = 0; // Initialize last_y

    mlx_hook(vars.win, 2, 1L << 0, close, &vars);
    mlx_mouse_hook(vars.win, mouse_scroll, &vars);
    mlx_loop(vars.mlx);
}

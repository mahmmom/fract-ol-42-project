#include "minilibx/mlx.h"
#include <math.h>
#include <stdlib.h>

typedef struct s_data
{
    void	*mlx;
	void	*win;
	void *img;
    char *addr;
    int bits_per_pixel;
    int line_length;
    int endian;
	int	visib;
} t_data;

void display_original_image(t_data *fractol)
{
    // Redraw your original image here
    int screen_width = 1920;
    int screen_height = 1080;
    int rect_width = 500;
    int rect_height = 500;
    int x = (screen_width - rect_width) / 2;
    int y = (screen_height - rect_height) / 2;
    int color = 0xFF0000;
    int i = 0;
    int j = 0;

    while (j < rect_height)
    {
        mlx_pixel_put(fractol->mlx, fractol->win, x + j, y + i, color);
        i = 0;
        while (i < rect_width)
        {
            mlx_pixel_put(fractol->mlx, fractol->win, x + i, y + j, color);
            i++;
        }
        j++;
    }
}


static void display_menu(void *mlx_ptr, void *win_ptr)
{
    mlx_string_put(mlx_ptr, win_ptr, 400, 400, 0xFFFFFF, "Option 1");
    mlx_string_put(mlx_ptr, win_ptr, 400, 410, 0xFFFFFF, "Option 2");
}

void toggle_menu(t_data *fractol)
{
    if (fractol->visib)
    {
        // Clear the menu area by drawing a background rectangle
        int menu_width = 800; // Adjust this as needed
        int menu_height = 600; // Adjust this as needed
        mlx_clear_window(fractol->mlx, fractol->win);
        display_original_image(fractol); // Redraw the original image
        fractol->visib = 0;
    }
    else
    {
        display_menu(fractol->mlx, fractol->win);
        fractol->visib = 1;
    }
}


int key_press(int keycode, t_data *fractol)
{
    if (fractol == NULL)
    {
        // Handle the case where fractol is not initialized properly, e.g., return or exit.
        return 1;
    }

    if (keycode == 46)
    {
        toggle_menu(fractol);
    }
    return (0);
}
int main()
{
	t_data *fractol = malloc(sizeof(t_data));

    if (fractol == NULL)
    {
        return 1;
    }

	fractol->mlx = mlx_init();

	fractol->win = mlx_new_window(fractol->mlx, 1920, 1080, "New Window");

	display_original_image(fractol);

	mlx_hook(fractol->win, 2, 1L<<0, key_press, fractol);;

	mlx_loop(fractol->mlx);

	return (0);
}
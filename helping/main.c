#include "minilibx/mlx.h"
#include <math.h>
#include <stdlib.h>

typedef struct s_data
{
    void *img;
    char *addr;
    int bits_per_pixel;
    int line_length;
    int endian;
} t_data;

int main()
{
	void	*mlx_ptr;
	void	*win_ptr;
	
	mlx_ptr = mlx_init();

	win_ptr = mlx_new_window(mlx_ptr, 1920, 1080, "New Window");

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
		mlx_pixel_put(mlx_ptr, win_ptr, x + j, y + i, color);
		i = 0;
		while (i < rect_width)
		{
			mlx_pixel_put(mlx_ptr, win_ptr, x + i, y + j, color);
			i++;
		}
		j++;
	}

	mlx_loop(mlx_ptr);

	return (0);
}
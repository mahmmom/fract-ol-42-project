#include "mlx.h"

#define WIDTH 800
#define HEIGHT 600
#define MAX_ITER 50

typedef struct s_complex
{
	double real;
	double imag;
} t_complex;

int newton_fractal(t_complex z, int max_iter)
{
    for (int i = 0; i < max_iter; i++)
    {
        double z_squared = z.real * z.real + z.imag * z.imag;
        if (z_squared < 1e-6)
            return i;
        t_complex numerator, denominator, derivative;

        // Define your polynomial and its derivative here
        // Example: z^3 - 1
        numerator.real = z.real * z.real * z.real - 3.0 * z.real * z.imag * z.imag - 1.0;
        numerator.imag = 3.0 * z.real * z.real * z.imag - z.imag * z.imag * z.imag;
        denominator.real = 3.0 * z.real * z.real - 3.0 * z.imag * z.imag;
        denominator.imag = 6.0 * z.real * z.imag;
        derivative.real = numerator.real / denominator.real;
        derivative.imag = numerator.imag / denominator.real;

        z.real -= derivative.real;
        z.imag -= derivative.imag;
    }
    return max_iter;
}

void draw_newton_fractal(void *mlx_ptr, void *win_ptr)
{
    for (int x = 0; x < WIDTH; x++)
    {
        for (int y = 0; y < HEIGHT; y++)
        {
            t_complex z;
            z.real = 2.0 * (x - WIDTH / 2) / (0.5 * WIDTH);
            z.imag = 2.0 * (y - HEIGHT / 2) / (0.5 * HEIGHT);
            int color = newton_fractal(z, MAX_ITER);

            // Color mapping based on 'color'
            unsigned char r = (color % 8) * 32;
            unsigned char g = (color % 16) * 16;
            unsigned char b = (color % 32) * 8;

            int rgb = (r << 16) | (g << 8) | b;
            mlx_pixel_put(mlx_ptr, win_ptr, x, y, rgb);
        }
    }
}

int main()
{
    void *mlx_ptr;
    void *win_ptr;

    mlx_ptr = mlx_init();
    win_ptr = mlx_new_window(mlx_ptr, WIDTH, HEIGHT, "Newton's Fractal");

    draw_newton_fractal(mlx_ptr, win_ptr);
    mlx_loop(mlx_ptr);

    return 0;
}

static t_complex newton_iteration(t_complex z, int power)
{
    t_complex numerator, denominator, derivative;

    // Define your polynomial and its derivative here based on the given power
    double power_minus_one = (double)(power - 1);
    double power_minus_two = (double)(power - 2);
    
    double z_real_power = pow(z.real, power_minus_one);
    double z_imag_power = pow(z.imag, power_minus_one);
    
    numerator.real = z_real_power * z.real - power_minus_two * z_real_power * z.imag * z.imag - 1.0;
    numerator.imag = power_minus_one * z_real_power * z.imag - z_imag_power * z.imag;
    denominator.real = power_minus_one * z_real_power - power_minus_two * z_real_power * z_imag_power;
    denominator.imag = power_minus_one * z_imag_power * z.real;
    
    derivative.real = numerator.real / denominator.real;
    derivative.imag = numerator.imag / denominator.real;

    z.real -= derivative.real;
    z.imag -= derivative.imag;

    return z;
}

static int newton_fractal(t_complex z, t_fractal *fractol)
{
    double z_squared;
    int     i;

    i = 0;
    while (i < fractol->iteration)
    {
        z_squared = z.real * z.real + z.imag * z.imag;
        if (z_squared < 1e-6)
            return (i);
        z = newton_iteration(z, power);
      i++;
    }
    return (fractol->iteration);
}

void draw_newton(t_fractal *fractol)
{
    int x;
    int y;
    t_complex c;
    int color;

    y = 0;
    while (y < HEIGHT)
    {
        x = 0;
        while (x < WIDTH)
        {
            c.x = (x - WIDTH / 2) / (0.5 * WIDTH * fractol->zoom) + fractol->shift_x;
            c.y = (y - HEIGHT / 2) / (0.5 * HEIGHT * fractol->zoom) + fractol->shift_y;
            color = newton_fractal(c, fractal);

            if (color == fractal->iteration)
                my_pixel_put(x, y, &fractol->img, BLACK);
            else
                my_pixel_put(x, y, &fractol->img, color * fractol->iteration);
            x++;
        }
        y++;
    }
    mlx_put_image_to_window(fractol->mlx, fractol->win, fractal->img.img, 0, 0);
}

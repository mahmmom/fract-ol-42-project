void	ft_zoom(int x, int y, t_fractol *data)
{
	data->x1 = (x / data->zoom + data->x1) - (x / (data->zoom * 1.3));
	data->y1 = (y / data->zoom + data->y1) - (y / (data->zoom * 1.3));
	data->zoom *= 1.3;
	data->it_max++;
}

void	ft_dezoom(int x, int y, t_fractol *data)
{
	data->x1 = (x / data->zoom + data->x1)  - (x / (data->zoom / 1.3));
	data->y1 = (y / data->zoom + data->y1) - (y / (data->zoom / 1.3));
	data->zoom /= 1.3;
	data->it_max--;
}

---------------------------------------------------------------------------------------------

  int	mouse_scroll(int button, int x, int y, t_mlx_info *info)
{
	double	mouse_y;
	double	mouse_x;

	mlx_clear_window(info->mlx_ptr, info->window_ptr);
	mouse_x = info->xmin
		+ (x * (info->xmax - info->xmin)) / 800;
	mouse_y = info->ymin
		+ (y * (info->ymax - info->ymin)) / HEIGHT;
	if (button == 4)
	{
		info->xmin = mouse_x + (info->xmin - mouse_x) / info->zoom;
		info->ymin = mouse_y + (info->ymin - mouse_y) / info->zoom;
		info->xmax = mouse_x + (info->xmax - mouse_x) / info->zoom;
		info->ymax = mouse_y + (info->ymax - mouse_y) / info->zoom;
	}
	if (button == 5)
	{
		info->xmin = mouse_x + (info->xmin - mouse_x) * info->zoom;
		info->ymin = mouse_y + (info->ymin - mouse_y) * info->zoom;
		info->xmax = mouse_x + (info->xmax - mouse_x) * info->zoom;
		info->ymax = mouse_y + (info->ymax - mouse_y) * info->zoom;
	}
	draw_shape(info);
	return (info->zoom);
}
---------------------------------------------------------------------------------------------
	
void	hundle_mouse_event(int button, int x, int y, t_display *mlx)
{
	if (button == 5)
	{
		mlx->max_it += 20;
		mlx->xscale *= 0.5;
		mlx->yscale *= 0.5;
		mlx->zoom_x = mlx->zoom_x - (x * mlx->xscale);
		mlx->zoom_y = mlx->zoom_y - (y * mlx->yscale);
	}
	else if (button == 4)
	{
		mlx->max_it -= 20;
		mlx->zoom_x = mlx->zoom_x + (x * mlx->xscale);
		mlx->zoom_y = mlx->zoom_y + (y * mlx->yscale);
		mlx->yscale /= 0.5;
		mlx->xscale /= 0.5;
	}
}
---------------------------------------------------------------------------------------------




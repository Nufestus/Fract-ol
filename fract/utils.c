/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aammisse <aammisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 11:22:10 by aammisse          #+#    #+#             */
/*   Updated: 2025/01/20 22:37:16 by aammisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	get_color(t_data *data, int iterations, int max_iterations)
{
	int		red;
	int		green;
	int		blue;
	float	ratio;

	ratio = (float)iterations / (float)max_iterations;
	red = 255 * ratio;
	green = 128 * ratio;
	blue = 128 * ratio;
	return ((red << data->hue.r) | (green << data->hue.g)
		| (blue << data->hue.b));
}

int	fractal_render(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y <= WINDOW_HEIGHT)
	{
		x = 0;
		while (x <= WINDOW_WIDTH)
		{
			if (!ft_strcmp(data->name, "mandelbrot"))
				mandelbrot(x, y, data);
			else if (!ft_strcmp(data->name, "julia"))
				julia(x, y, data);
			else if (!ft_strcmp(data->name, "tricorn"))
				tricorn(x, y, data);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->image.img, 0, 0);
	return (0);
}

void	julia(int x, int y, t_data *data)
{
	int		n;
	t_value	z;
	t_value	c;

	n = 0;
	z.x = (scale(x, -2, 2, WINDOW_WIDTH) * data->zoom) + data->shiftx;
	z.y = (scale(y, 2, -2, WINDOW_HEIGHT) * data->zoom) + data->shifty;
	c.x = data->mouse_re;
	c.y = data->mouse_im;
	while (n < data->iteration)
	{
		z = sum_complex(sqrt_complex(z), c);
		if (((z.x + z.x) + (z.y * z.y)) > data->escape_value)
		{
			data->color = get_color(data, n * 2.5, data->iteration * 4.5);
			my_mlx_pixel_put(&data->image, x, y, data->color);
			return ;
		}
		n++;
	}
	my_mlx_pixel_put(&data->image, x, y, INSIDECOLOR);
}

void	mandelbrot(int x, int y, t_data *data)
{
	int		n;
	t_value	z;
	t_value	c;

	n = 0;
	z.x = 0.0;
	z.y = 0.0;
	c.x = (scale(x, -2, 2, WINDOW_WIDTH) * data->zoom) + data->shiftx;
	c.y = (scale(y, 2, -2, WINDOW_HEIGHT) * data->zoom) + data->shifty;
	while (n < data->iteration)
	{
		z = sum_complex(sqrt_complex(z), c);
		if (((z.x + z.x) + (z.y * z.y)) > data->escape_value)
		{
			data->color = get_color(data, n * 2.5, data->iteration * 4.5);
			my_mlx_pixel_put(&data->image, x, y, data->color);
			return ;
		}
		n++;
	}
	my_mlx_pixel_put(&data->image, x, y, INSIDECOLOR);
}

void	tricorn(int x, int y, t_data *data)
{
	int		n;
	t_value	z;
	t_value	c;
	t_value	temp;

	n = 0;
	c.x = (scale(x, -2, 2, WINDOW_WIDTH) * data->zoom) + data->shiftx;
	c.y = (scale(y, 2, -2, WINDOW_HEIGHT) * data->zoom) + data->shifty;
	z.x = 0.0;
	z.y = 0.0;
	while (n < data->iteration)
	{
		temp.x = z.x * z.x - z.y * z.y + c.x;
		temp.y = -2 * z.x * z.y + c.y;
		z = temp;
		if (((z.x + z.x) + (z.y * z.y)) > data->escape_value)
		{
			data->color = get_color(data, n * 2.5, data->iteration * 4.5);
			my_mlx_pixel_put(&data->image, x, y, data->color);
			return ;
		}
		n++;
	}
	my_mlx_pixel_put(&data->image, x, y, INSIDECOLOR);
}

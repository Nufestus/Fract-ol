/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctrldata.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aammisse <aammisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 18:12:09 by aammisse          #+#    #+#             */
/*   Updated: 2025/01/13 09:53:16 by aammisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	data_init(t_data *data)
{
	data->escape_value = ESCAPEVALUE;
	data->iteration = ITERATION;
	data->hue.r = 9;
	data->hue.g = 15;
	data->hue.b = 8;
	data->shiftx = 0.0;
	data->shifty = 0.0;
	data->zoom = ZOOMVALUE;
}

void	clear_data(t_data *data)
{
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->image.img)
		mlx_destroy_image(data->mlx, data->image.img);
	if (data->mlx)
		mlx_destroy_display(data->mlx);
	free(data->mlx);
}

void	fractal_init(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
	{
		clear_data(data);
		exit(EXIT_FAILURE);
		return ;
	}
	data->win = mlx_new_window(data->mlx, WINDOW_WIDTH, WINDOW_HEIGHT,
			data->name);
	if (!data->win)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
	data->image.img = mlx_new_image(data->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (!data->image.img)
	{
		mlx_destroy_window(data->mlx, data->win);
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
	data->image.addr = mlx_get_data_addr(data->image.img, &data->image.bpp,
			&data->image.line_length, &data->image.endian);
	data_init(data);
}

int	closewin(t_data *data)
{
	clear_data(data);
	exit(0);
	return (0);
}

void	my_mlx_pixel_put(t_info *image, int x, int y, int color)
{
	int	offset;

	offset = 0;
	offset = (y * image->line_length) + (x * (image->bpp / 8));
	*(unsigned int *)(image->addr + offset) = color;
}

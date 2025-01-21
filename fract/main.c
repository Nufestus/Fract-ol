/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aammisse <aammisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 12:03:43 by aammisse          #+#    #+#             */
/*   Updated: 2025/01/21 11:33:29 by aammisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	handlekey(int keycode, t_data *data)
{
	if (keycode == ESCAPE_KEY)
	{
		clear_data(data);
		exit(EXIT_SUCCESS);
	}
	else if (keycode == TAB_KEY)
	{
		data->hue.r += 2;
		data->hue.g += 4;
		data->hue.b += 1;
	}
	else if (keycode == PAGEUP_KEY)
		data->iteration += 10;
	else if (keycode == PAGEDOWN_KEY)
		data->iteration -= 10;
	else if (keycode == RIGHT_ARROW)
		data->shiftx += SHIFT_VALUE * data->zoom;
	else if (keycode == LEFT_ARROW)
		data->shiftx -= SHIFT_VALUE * data->zoom;
	else if (keycode == UP_ARROW)
		data->shifty += SHIFT_VALUE * data->zoom;
	else if (keycode == DOWN_ARROW)
		data->shifty -= SHIFT_VALUE * data->zoom;
	return (0);
}

int mousezoom(int button, int x, int y, t_data *data)
{
	double mouse_re = (scale(x, -2, 2, WINDOW_WIDTH) * data->zoom) + data->shiftx;
	double mouse_im = (scale(y, 2, -2, WINDOW_HEIGHT) * data->zoom) + data->shifty;
	if (button == MOUSE_DOWN)
	{
		data->zoom *= 0.95;
		data->shiftx += (mouse_re - data->shiftx) * SHIFT_VALUE;
		data->shifty += (mouse_im - data->shifty) * SHIFT_VALUE;
	}
	else if (button == MOUSE_UP)
	{
		data->zoom *= 1.05;
		data->shiftx -= (mouse_re - data->shiftx) * SHIFT_VALUE;
		data->shifty -= (mouse_im - data->shifty) * SHIFT_VALUE;
	}
	return (0);
}

int	handlemouse(int x, int y, t_data *data)
{
	data->mouse_re = (scale(x, -2, 2, WINDOW_WIDTH) * data->zoom) + data->shiftx;
	data->mouse_im = (scale(y, 2, -2, WINDOW_HEIGHT) * data->zoom) + data->shifty;
	return (0);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

int	parse(t_data *data, int argc, char **argv)
{
	if (argc == 2 && !ft_strcmp(argv[1], "julia"))
	{
		// if (!ft_isdp(argv[2]) || !ft_isdp(argv[3]))
		// 	return (0);
		data->name = argv[1];
		// data->value.x = ft_atod(argv[2]);
		// data->value.y = ft_atod(argv[3]);
	}
	else if (argc == 2 && !ft_strcmp(argv[1], "mandelbrot"))
		data->name = argv[1];
	else if (argc == 2 && !ft_strcmp(argv[1], "tricorn"))
		data->name = argv[1];
	else
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (!parse(&data, argc, argv))
	{
		ft_printf(ERROR_MESSAGE);
		ft_printf(ERROR_MESSAGE2);
		exit(EXIT_SUCCESS);
		return (0);
	}
	fractal_init(&data);
	mlx_loop_hook(data.mlx, fractal_render, &data);
	// mlx_mouse_hook(data.win, handlemouse, &data);
	mlx_hook(data.win, MotionNotify, PointerMotionMask, handlemouse, &data);
	mlx_hook(data.win, KeyPress, KeyPressMask, handlekey, &data);
	mlx_hook(data.win, DestroyNotify, NoEventMask, closewin, &data);
	mlx_loop(data.mlx);
}

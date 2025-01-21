/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aammisse <aammisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 18:11:05 by aammisse          #+#    #+#             */
/*   Updated: 2025/01/14 11:10:29 by aammisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	scale(double unscaled_num, double new_min, double new_max,
			double old_max)
{
	return ((new_max - new_min) * unscaled_num / old_max + new_min);
}

t_value	sum_complex(t_value z1, t_value z2)
{
	t_value	result;

	result.x = z1.x + z2.x;
	result.y = z1.y + z2.y;
	return (result);
}

t_value	sqrt_complex(t_value z)
{
	t_value	result;

	result.x = (z.x * z.x) - (z.y * z.y);
	result.y = 2 * z.x * z.y;
	return (result);
}

double	ft_atod(char *str)
{
	double	result;
	double	fraction;
	int		sign;
	int		divisor;

	sign = 1;
	divisor = 1;
	result = 0.0;
	fraction = 0.0;
	while (ft_isspace(*str))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (ft_isdigit(*str))
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	result = helpfunc(str, fraction, divisor, result);
	return (result * sign);
}

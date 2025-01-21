/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aammisse <aammisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 19:20:29 by aammisse          #+#    #+#             */
/*   Updated: 2025/01/16 11:33:35 by aammisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_isspace(int c)
{
	if (c == ' ')
		return (1);
	return (0);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_isdp(char *s)
{
	int	i;

	i = 0;
	if (s[i] == '.')
		return (0);
	else if (s[i] == '-' || s[i] == '+')
		i++;
	while (s[i])
	{
		if ((s[i] >= '0' && s[i] <= '9') || s[i] == '.')
		{
			if (s[i] == '.' && s[i + 1] == '.')
				return (0);
			i++;
		}
		else
			return (0);
	}
	if (s[i - 1] == '.')
		return (0);
	return (1);
}

double	helpfunc(char *c, double fraction, int divisor, double result)
{
	if (*c == '.')
	{
		c++;
		while (ft_isdigit(*c))
		{
			fraction = fraction * 10 + (*c - '0');
			divisor *= 10;
			c++;
		}
		result += fraction / divisor;
	}
	return (result);
}

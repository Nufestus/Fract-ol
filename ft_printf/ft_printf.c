/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aammisse <aammisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 20:23:42 by aammisse          #+#    #+#             */
/*   Updated: 2025/01/14 14:51:45 by aammisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	parser(char c, va_list args)
{
	int	res;

	res = 0;
	if (c == 'c')
		res += ft_putchar(va_arg(args, int));
	else if (c == 's')
		res += ft_printstr(va_arg(args, char *));
	else if (c == 'd' || c == 'i')
		res += ft_printnbr(va_arg(args, int));
	else if (c == 'p')
		res += ft_printptr(va_arg(args, void *));
	else if (c == 'u')
		res += ft_printunbr(va_arg(args, unsigned int));
	else if (c == 'X')
		res += ft_printhexup(va_arg(args, unsigned int));
	else if (c == 'x')
		res += ft_printhexlow(va_arg(args, unsigned int));
	else
		res += write(1, &c, 1);
	return (res);
}

int	ft_printf(const char *buffer, ...)
{
	int		i;
	int		res;
	va_list	args;

	va_start(args, buffer);
	i = 0;
	res = 0;
	if (write(1, NULL, 0) == -1)
		return (va_end(args), -1);
	while (buffer[i] != '\0')
	{
		if (buffer[i] == '%' && buffer[i + 1])
		{
			res += parser(buffer[i + 1], args);
			i++;
		}
		else
			res += write(1, &buffer[i], 1);
		i++;
	}
	va_end(args);
	return (res);
}

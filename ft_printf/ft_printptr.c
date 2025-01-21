/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aammisse <aammisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 19:38:41 by aammisse          #+#    #+#             */
/*   Updated: 2024/11/20 21:08:12 by aammisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	printhex(size_t a)
{
	int				res;

	res = 0;
	if (a >= 16)
		res += printhex(a / 16);
	res += ft_convert_hex(a % 16);
	return (res);
}

int	ft_printptr(void *ptr)
{
	int	res;

	res = 0;
	res += write(1, "0x", 2);
	res += printhex((size_t)ptr);
	return (res);
}

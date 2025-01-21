/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhexup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aammisse <aammisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 19:34:52 by aammisse          #+#    #+#             */
/*   Updated: 2024/11/20 20:46:29 by aammisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	convert_hex(unsigned int a)
{
	char	*hex;

	hex = "0123456789ABCDEF";
	return (write(1, &hex[a], 1));
}

int	ft_printhexup(unsigned int a)
{
	int		res;

	res = 0;
	if (a >= 16)
		res += ft_printhexup(a / 16);
	res += convert_hex(a % 16);
	return (res);
}

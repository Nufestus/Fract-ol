/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhexlow.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aammisse <aammisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 19:33:25 by aammisse          #+#    #+#             */
/*   Updated: 2024/11/20 20:46:33 by aammisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printhexlow(unsigned int a)
{
	int	res;

	res = 0;
	if (a >= 16)
		res += ft_printhexlow(a / 16);
	res += ft_convert_hex(a % 16);
	return (res);
}

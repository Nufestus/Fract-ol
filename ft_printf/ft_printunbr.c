/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printunbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aammisse <aammisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 17:36:43 by aammisse          #+#    #+#             */
/*   Updated: 2024/11/20 20:13:53 by aammisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_printnbr_helper(unsigned int n, int *res)
{
	if (n >= 10)
	{
		ft_printnbr_helper(n / 10, res);
	}
	*res += ft_putchar((n % 10) + '0');
}

int	ft_printunbr(unsigned int n)
{
	int	res;

	res = 0;
	ft_printnbr_helper(n, &res);
	return (res);
}

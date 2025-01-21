/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aammisse <aammisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:43:45 by aammisse          #+#    #+#             */
/*   Updated: 2024/11/20 16:58:44 by aammisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_printnbr_helper(int n, int *res)
{
	if (n < 0)
	{
		*res += ft_putchar('-');
		n = -n;
	}
	if (n >= 10)
	{
		ft_printnbr_helper(n / 10, res);
	}
	*res += ft_putchar((n % 10) + '0');
}

int	ft_printnbr(int n)
{
	int	res;

	res = 0;
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	ft_printnbr_helper(n, &res);
	return (res);
}

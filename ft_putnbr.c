/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfournie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 22:14:57 by gfournie          #+#    #+#             */
/*   Updated: 2015/03/27 19:38:41 by gfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_putnbr(int n)
{
	if (n < 0)
	{
		ft_putchar('-');
		n = n * -1;
	}
	if (n == -2147483648)
	{
		write(1, "2147483648", 11);
		return ;
	}
	if (n > 9)
		ft_putnbr((n - (n % 10)) / 10);
	ft_putchar((n % 10) + 48);
}
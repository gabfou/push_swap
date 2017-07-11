/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfournie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 15:26:05 by gfournie          #+#    #+#             */
/*   Updated: 2015/03/27 19:35:28 by gfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*init(int *a, int *b, const char *str)
{
	*a = 0;
	*b = 1;
	while ((*str == ' ') || (*str == '\n')
		|| (*str == '\t') || (*str == '\v')
		|| (*str == '\r') || (*str == '\f'))
		str++;
	return ((char*)str);
}

int			ft_atoi(const char *str)
{
	int res;
	int sign;

	if (str == NULL)
		return (0);
	str = init(&res, &sign, str);
	if (str[0] == '-')
		sign = -1;
	if (str[0] == '-' || str[0] == '+')
		str++;
	while ((str)[0] != '\0')
	{
		if (str[0] >= '0' && str[0] <= '9')
			res = res * 10 + str[0] - '0';
		else
			return (sign * res);
		str++;
	}
	return (sign * res);
}

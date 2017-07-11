/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfournie <gfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/08/03 16:13:44 by gfournie          #+#    #+#             */
/*   Updated: 2015/03/27 19:40:50 by gfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

unsigned int ft_strlen(const char *str)
{
	int i;

	i = 0;
	while (*(str + i) != '\0')
		i++;
	return (i);
}

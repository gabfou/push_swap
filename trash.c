/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trash.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfournie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/25 16:25:11 by gfournie          #+#    #+#             */
/*   Updated: 2015/03/25 17:57:39 by gfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_pile	*trash1(t_pile *tmp, int *j)
{
	if (tmp->nb < *j)
		*j = tmp->nb;
	return (tmp->next);
}

void	trash2(t_pile *tmp, t_pile **p, t_pile **p2, int j)
{
	while (tmp && tmp->next)
	{
		if (tmp->next->nb != j && tmp->nb > tmp->next->nb)
		{
			*p = rotator(*p, pilestrlen(*p), tmp->nb, *p2);
			tablator(p, p2, 0, "sa");
			break ;
		}
		tmp = tmp->next;
	}
}

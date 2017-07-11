/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sp.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfournie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/02 16:52:21 by gfournie          #+#    #+#             */
/*   Updated: 2015/02/02 17:03:08 by gfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_pile	*pileswap(t_pile *p)
{
	t_pile *tmp;

	if (p && p->next)
	{
		tmp = p->next;
		p->next = p->next->next;
		tmp->next = p;
		p = tmp;
	}
	return (p);
}

t_pile	*pilerotate(t_pile *p)
{
	t_pile *tmp;
	t_pile *tmp2;

	tmp = NULL;
	tmp2 = NULL;
	if (p && p->next)
	{
		tmp = p;
		tmp2 = p->next;
		p = p->next;
		tmp->next = NULL;
		while (tmp2->next)
			tmp2 = tmp2->next;
		tmp2->next = tmp;
	}
	return (p);
}

t_pile	*pilereverse(t_pile *p)
{
	t_pile *tmp;
	t_pile *tmp2;

	if (p && p->next)
	{
		tmp2 = p;
		while (tmp2->next->next)
			tmp2 = tmp2->next;
		tmp = tmp2->next;
		tmp2->next = NULL;
		tmp->next = p;
		p = tmp;
	}
	return (p);
}

void	pilepush(t_pile **src, t_pile **dst)
{
	t_pile *tmp;

	if (!src[0])
		return ;
	tmp = *src;
	*src = (*src)->next;
	tmp->next = *dst;
	*dst = tmp;
}

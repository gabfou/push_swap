/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfournie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/02 17:09:09 by gfournie          #+#    #+#             */
/*   Updated: 2015/04/14 19:57:00 by gfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_pile	*avancator(t_pile *tmp, int *j)
{
	j[0] = j[0] + 1;
	return (tmp->next);
}

t_pile			*rotator(t_pile *p, int i, int nb, t_pile *p2)
{
	int		j;
	t_pile	*tmp;

	j = 0;
	tmp = p;
	(void)p2;
	while (tmp && tmp->nb != nb)
		tmp = avancator(tmp, &j);
	if (j > i / 2)
		while (p && p->nb != nb)
			tablator(&p, &p2, 2, "rra");
	else
	{
		while (p && p->nb != nb)
			tablator(&p, &p2, 1, "ra");
	}
	return (p);
}

int				pilestrlen(t_pile *p)
{
	t_pile	*tmp;
	int		i;

	i = 0;
	tmp = p;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

void			printator(t_pile *p, char *s)
{
	t_pile *tmp;

	tmp = p;
	write(1, "\n", 1);
	ft_putstr(s);
	while (tmp)
	{
		write(1, " ", 1);
		ft_putnbr(tmp->nb);
		tmp = tmp->next;
	}
	write(1, "\n", 1);
}

int				option(char *s)
{
	static int *o;

	if (s)
	{
		o = malloc(sizeof(o));
		if (s[0] == '-' && s[1] == 'v')
			*o = 1;
		else
			*o = 0;
	}
	if (o)
		return (*o);
	return (-1);
}

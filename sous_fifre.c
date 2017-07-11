/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sous_fifre.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfournie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/02 16:34:19 by gfournie          #+#    #+#             */
/*   Updated: 2015/03/25 17:55:27 by gfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		tablator(t_pile **p1, t_pile **p2, int i, char *s)
{
	static char	*t;

	if (t && !option(NULL))
		write(1, " ", 1);
	else
		t = malloc(sizeof(t));
	ft_putstr(s);
	*p1 = (i == 0) ? pileswap(*p1) : *p1;
	if (i == 1)
		*p1 = pilerotate(*p1);
	if (i == 2)
		*p1 = pilereverse(*p1);
	if (i == 3)
		pilepush(p1, p2);
	if (i == 4)
		pilepush(p2, p1);
	if (option(NULL))
	{
		write(1, " :\n", 3);
		if (p1)
			printator(*p1, "p1 =");
		if (p2)
			printator(*p2, "p2 =");
		write(1, "\n", 1);
	}
}

static int	verif(t_pile *p)
{
	t_pile	*tmp;
	int		i;
	t_pile	*tmp2;
	int		j;

	i = 0;
	j = -1;
	tmp = p;
	tmp2 = NULL;
	while (tmp && tmp->next)
	{
		if (tmp->nb > tmp->next->nb)
			i++;
		tmp2 = tmp;
		tmp = tmp->next;
	}
	if (tmp && p && p != tmp && (tmp->nb > p->nb))
		i++;
	return (i);
}

void		initp(t_pile **p, t_pile **p2, int j, int z)
{
	int		k;
	t_pile	*tmp;
	int		i;

	i = pilestrlen(*p);
	while (j++ < i && verif(*p) > z + 1)
	{
		if (p[0] && p[0]->next && p[0]->nb > p[0]->next->nb && verif(*p) < 3)
		{
			tablator(p, p2, 0, "sa");
			continue ;
		}
		tmp = *p;
		if (*p)
			k = p[0]->nb;
		while (tmp && *p)
		{
			if (k > tmp->nb)
				k = tmp->nb;
			tmp = tmp->next;
		}
		*p = rotator(*p, i - j + 1, k, *p2);
		tablator(p, p2, 3, "pb");
	}
}

void		henchman(t_pile *p)
{
	t_pile	*p2;
	int		j;
	t_pile	*tmp;

	j = 0;
	p2 = NULL;
	initp(&p, &p2, j, 1);
	if (((tmp) = (p)))
		j = p->nb;
	while (tmp)
		tmp = trash1(tmp, &j);
	tmp = p;
	trash2(tmp, &p, &p2, j);
	initp(&p, &p2, 0, 0);
	if (((tmp) = (p)))
		j = p->nb;
	while (tmp)
		tmp = trash1(tmp, &j);
	p = rotator(p, pilestrlen(p), j, p2);
	while (p2)
		tablator(&p, &p2, 4, "pa");
}

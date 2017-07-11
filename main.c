/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfournie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/02 16:08:52 by gfournie          #+#    #+#             */
/*   Updated: 2015/03/25 17:59:35 by gfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			ft_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

static long int	ft_atoi2(const char *str)
{
	long int	res;
	int			sign;
	int			i;

	if (str == NULL)
		return (0);
	res = 0;
	sign = 1;
	i = -1;
	while ((str[i + 1] == ' ') || (str[i + 1] == '\n')
		|| (str[i + 1] == '\t') || (str[i + 1] == '\v')
		|| (str[i + 1] == '\r') || (str[i + 1] == '\f'))
		i++;
	if (str[i + 1] == '-')
		sign = -1;
	if (str[i + 1] == '-' || str[i + 1] == '+')
		i++;
	while (str[++i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
			res = res * 10 + str[i] - '0';
		else
			return (sign * res);
	}
	return ((long int)sign * res);
}

t_pile			*ft_spepushfront(t_pile *p, char *s)
{
	int			i;
	t_pile		*r;
	long int	nb;

	r = NULL;
	i = 0;
	if (!s || !s[0])
		ft_error();
	while (s[i] && ((s[i] >= '0' && s[i] <= '9') || (s[i] == '-' && i == 0)))
		i++;
	if (s[i] != 0 || ft_strlen(s) > 11)
		ft_error();
	nb = ft_atoi2(s);
	if (!(nb < 2147483648 && nb > -2147483649))
		ft_error();
	r = malloc(sizeof(r));
	r->nb = nb;
	r->next = p;
	return (r);
}

static void		verif(t_pile *p)
{
	t_pile	*tmp;
	t_pile	*tmp2;
	int		i;

	tmp = p;
	while (tmp)
	{
		i = 0;
		tmp2 = p;
		while (tmp2)
		{
			if (tmp2->nb == tmp->nb)
				i++;
			tmp2 = tmp2->next;
		}
		if (i > 1)
			ft_error();
		tmp = tmp->next;
	}
}

int				main(int argc, char **argv)
{
	int		i;
	int		j;
	t_pile	*p;

	i = argc;
	j = 0;
	if (i - 1 > 0)
		j = option(argv[1]);
	p = NULL;
	while (--i > j)
		p = ft_spepushfront(p, argv[i]);
	verif(p);
	henchman(p);
	return (0);
}

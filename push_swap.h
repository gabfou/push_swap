/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfournie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/02 17:04:57 by gfournie          #+#    #+#             */
/*   Updated: 2015/03/27 19:43:13 by gfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct	s_pile
{
	int				nb;
	struct s_pile	*next;
}				t_pile;

void			ft_error(void);
t_pile			*ft_spepushfront(t_pile	*p, char *s);
void			pilepush(t_pile **src, t_pile **dst);
void			pilepush(t_pile **src, t_pile **dst);
t_pile			*pilerotate(t_pile *p);
t_pile			*pileswap(t_pile *p);
t_pile			*pilereverse(t_pile *p);
void			henchman(t_pile *p);
t_pile			*rotator(t_pile *p, int i, int nb, t_pile *p2);
int				pilestrlen(t_pile *p);
t_pile			*pileswap(t_pile *p);
void			printator(t_pile *p, char *s);
void			tablator(t_pile **p1, t_pile **p2, int i, char *s);
int				option(char *s);
t_pile			*trash1(t_pile *tmp, int *j);
void			trash2(t_pile *tmp, t_pile **p1, t_pile **p2, int j);
void			initp(t_pile **p, t_pile **p2, int j, int z);
void			ft_putnbr(int n);
void			ft_putstr(char const *c);
unsigned int	ft_strlen(const char *str);
void			ft_putchar(char c);

#endif

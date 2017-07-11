#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gfournie <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/04 12:38:41 by gfournie          #+#    #+#              #
#    Updated: 2015/03/27 19:44:02 by gfournie         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = push_swap

FLAG = -Wall -Werror -Wextra

SRC = main.c misc.c sous_fifre.c sp.c trash.c ft_putnbr.c ft_putstr.c ft_strlen.c ft_putchar.c

OBJ = main.o sous_fifre.o misc.o sp.o trash.o ft_putnbr.o ft_putstr.o ft_strlen.o ft_putchar.o

all:$(NAME)

$(NAME):
	gcc $(FLAG) -c $(SRC)
	gcc -o $(NAME) $(FLAG) $(OBJ)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lsuau <lsuau@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/04 10:06:54 by lsuau             #+#    #+#              #
#    Updated: 2021/11/16 12:15:08 by lsuau            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAMEX = libftprintf.a

INC = ft_printf.h

SRC = ft_printf.c ft_printf_char.c ft_printf_nbr.c ft_printf_hexa.c

OBJS = ${SRC:.c=.o}

all : ${NAMEX}

%.o : %.c ${INC}
	gcc -Wall -Werror -Wextra -I ${INC} -c $< -o $@

${NAMEX}: ${OBJS} ${INC}
	ar -rsc $@ ${OBJS}

clean :
	rm -f ${OBJS}

fclean : clean
	rm  -f ${NAMEX}

re : fclean all

.PHONY: bonus all clean fclean re

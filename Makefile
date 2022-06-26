# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atouati <atouati@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/04 15:48:45 by atouati           #+#    #+#              #
#    Updated: 2021/12/05 22:56:18 by atouati          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= ft_putchar.c ft_putstr.c ft_putnbr.c ft_hexadecimal_x.c ft_pointer.c ft_unsigned.c ft_printf.c \

OBJS	= ${SRCS:.c=.o}

NAME	= libftprintf.a

LIB	= ar -rc
CC	= cc
RM	= rm -f

CFLAGS	= -Wall -Werror -Wextra

all: ${NAME}

${NAME}: ${OBJS}
	${LIB} ${NAME} ${OBJS}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all
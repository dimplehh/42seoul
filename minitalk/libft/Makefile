# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyunhlee <hyunhlee@42seoul.student.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/23 18:42:41 by hyunhlee          #+#    #+#              #
#    Updated: 2021/12/03 14:57:51 by hyunhlee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=gcc
CFLAGS=-Wall -Wextra -Werror
NAME=libft.a
SOURCE_FILE=ft_strlen.c ft_atoi.c ft_itoa.c ft_calloc.c ft_bzero.c\
			ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c
INCLUDE=libft.h
OBJS=${SOURCE_FILE:.c=.o}

.c.o:
	${CC} ${CFLAGS} -I $(INCLUDE) -c $< -o ${<:.c=.o}

${NAME}:${OBJS}
	ar rc $@ ${OBJS}

all:${NAME}

clean:
	rm -f ${OBJS}

fclean:
	rm -f ${OBJS} ${NAME}

re:fclean all

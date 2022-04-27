# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyunhlee <hyunhlee@42seoul.student.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/27 17:32:54 by hyunhlee          #+#    #+#              #
#    Updated: 2022/04/27 17:32:54 by hyunhlee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS=-Wall -Wextra -Werror
NAME=libft.a
SOURCE_FILE=ft_atoi.c ft_atol.c ft_isdigit.c ft_putendl_fd.c\
			ft_split.c ft_strchr.c
INCLUDE=../header.h
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

.PHONY : all clean fclean re

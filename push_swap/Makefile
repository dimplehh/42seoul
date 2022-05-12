# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyunhlee <hyunhlee@42seoul.student.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/27 17:32:38 by hyunhlee          #+#    #+#              #
#    Updated: 2022/04/27 17:32:39 by hyunhlee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=gcc
CCFLAGS=-Wall -Wextra -Werror -g
NAME=push_swap
SOURCE_FILE=push_swap.c operator.c operator2.c\
deque.c deque2.c check.c check2.c sort_small.c
OBJS=${SOURCE_FILE:.c=.o}

.c.o:
	${CC} ${CCFLAGS} -c $< -o ${<:.c=.o}

${NAME}:${OBJS}
	make -C libft
	${CC} ${CCFLAGS} -o ${NAME} -Llibft -lft ${OBJS}

all:${NAME}

clean:
	rm -f *.o
	rm -f libft/*.o

fclean:clean
	rm -f libft/libft.a
	rm -f ${NAME}

re:fclean all

.PHONY: all clean fclean re

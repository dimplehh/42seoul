# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyunhlee <hyunhlee@42seoul.student.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/24 16:23:50 by hyunhlee          #+#    #+#              #
#    Updated: 2021/06/24 16:23:52 by hyunhlee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=gcc
CFLAGS=-Wall -Wextra -Werror
LIBFT=libft
LIBFT_LIB=libft.a
NAME=libftprintf.a
SOURCE_FILE=ft_printf.c in_printf.c ft_buflen.c \
	printf_c.c printf_diu.c printf_sp.c printf_x.c
INCLUDE=ft_printf.h
OBJS=$(SOURCE_FILE:.c=.o)

.c.o:
	$(CC) $(CFLAGS) -I $(INCLUDE) -c $< -o $(<:.c=.o)

$(NAME) : $(OBJS)
	make all -C $(LIBFT)/
	cp $(LIBFT)/$(LIBFT_LIB) $(NAME)
	ar rc $(NAME) $(OBJS)

all : $(NAME)

fclean :
	rm -rf $(OBJS)
	rm -rf $(NAME)
	make fclean -C $(LIBFT)

clean : 
	rm -rf $(OBJS)
	make clean -C $(LIBFT)

re : fclean all
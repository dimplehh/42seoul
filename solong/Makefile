CC = gcc
CFLAGS=-Wall -Wextra -Werror
NAME=a.out
SOURCE_FILE=ft_memcpy.c ft_strcpy.c ft_split.c ft_strlen.c\
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
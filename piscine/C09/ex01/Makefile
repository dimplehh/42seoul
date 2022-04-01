CC=gcc
CFLAGS=-Wall -Wextra -Werror
TARGET=libft.a
SOURCE=srcs
SOURCE_FILE=${SOURCE}/ft_putchar.c ${SOURCE}/ft_swap.c ${SOURCE}/ft_putstr.c ${SOURCE}/ft_strlen.c ${SOURCE}/ft_strcmp.c
INCLUDES=includes
OBJS=${SOURCE_FILE:.c=.o}

.c.o:
	${CC} ${CFLAGS} -I $(INCLUDES) -c $< -o ${<:.c=.o}

${TARGET}:${OBJS}
	ar rc $@ ${OBJS}

all:${TARGET}

clean:
	rm -f ${OBJS}

fclean:
	rm -f ${OBJS} ${TARGET}

re:fclean all

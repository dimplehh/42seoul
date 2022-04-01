CC=gcc
CFLAGS=-Wall -Wextra -Werror
TARGET=do-op
SOURCE=srcs
SOURCE_FILE=${SOURCE}/ft_atoi.c ${SOURCE}/ft_op.c ${SOURCE}/ft_putchar.c ${SOURCE}/ft_putnbr.c ${SOURCE}/ft_putstr.c main.c
INCLUDES=includes
OBJS=${SOURCE_FILE:.c=.o}

.c.o:
	${CC} ${CFLAGS} -I ${INCLUDES} -c $< -o ${<:.c=.o}

${TARGET}:${OBJS}
	${CC} ${CFLAGS} -o $@ ${OBJS}

clean:
	rm -f ${OBJS} ${TARGET}

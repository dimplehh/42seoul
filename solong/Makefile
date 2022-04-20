CC = gcc
CFLAGS=-Wall -Wextra -Werror
XMLFLAGS=-lmlx -framework OpenGL -framework Appkit
NAME=a.out
SOURCE_FILE=main.c init_game.c draw_map.c change_map.c valid_table.c
INCLUDE=libft.h
OBJS=${SOURCE_FILE:.c=.o}

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:${OBJS}
	make -C mlx
	make -C libft
	${CC} ${CFLAGS} -c gnl/*.c -D BUFFER_SIZE=10
	${CC} ${XMLFLAGS} -L. libft/libft.a get_*.o ${OBJS}

all:${NAME}

clean:
	rm -f *.o
	rm -f mlx/*.o
	rm -f libft/*.o

fclean:clean
	rm -f libft/libft.a
	rm -f ${NAME}

re:fclean all

.PHONY:	all clean fclean re
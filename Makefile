NAME = gnl
B_NAME = bgnl
CC = gcc -Wall -Wextra -Werror
SRC = get_next_line.c get_next_line_utils.c main.c
B_SRC = get_next_line_bonus.c get_next_line_utils_bonus.c main_bonus.c
OBJS = ${SRCS:.c=.o}
B_OBJS = ${BONUS:.c=.o}
FLAG = -D
SIZE = BUFFER_SIZE=1000

${NAME}: ${OBJS}
	${CC} ${FLAG} ${SIZE} ${SRC} -o ${NAME}

${B_NAME}: ${B_OBJS}
	${CC} ${FLAG} ${SIZE} ${B_SRC} -o ${B_NAME}

all: ${NAME}

bonus: ${B_NAME}

clean:
	rm -f ${OBJS} ${B_OBJS}

fclean: clean
	rm -f ${NAME} ${B_NAME}

re: fclean all

.PHONY: all bonus clean fclean re

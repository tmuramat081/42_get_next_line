NAME = gnl
CC = gcc -Wall -Wextra -Werror -g -fsanitize=address
SRC = get_next_line.c get_next_line_utils.c main.c
B_SRC = 
OBJS = ${SRCS:.c=.o}
B_OBJS = ${BONUS:.c=.o}
FLAG = -D
SIZE = BUFFER_SIZE=1000

${NAME}: ${OBJS}
	${CC} ${FLAG} ${SIZE} ${SRC} -o ${NAME}

all: ${NAME}

bonus: ${OBJS} ${B_OBJS}
	 ${AR} ${NAME} ${OBJS} ${B_OBJS} 

clean:
	rm -f ${OBJS} ${B_OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all bonus clean fclean re

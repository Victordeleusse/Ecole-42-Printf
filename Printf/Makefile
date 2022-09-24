NAME = libftprintf.a

SRCS = $(wildcard *.c) $(wildcard ./Libft/annexes_printf/*.c) 

OBJS = ${SRCS:.c=.o}

CC = gcc -Wall -Wextra 

%.o: %.c libftprintf.h
			${CC} -I. -c $< -o ${<:.c=.o}

all: 	${NAME}

${NAME}:	${OBJS} libftprintf.h
				ar -rsc ${NAME} ${OBJS}

clean:	
		rm -f ${OBJS}

fclean:	clean
		rm -f ${NAME}

re:	fclean all

.PHONY: all clean fclean re 
NAME = ft_printf.a

SRCS = $(wildcard *.c) 

OBJS = ${SRCS:.c=.o}

CC = gcc -Wall -Werror -Wextra -I ./

%.o: %.c ft_printf.h
			${CC} -I. -c $< -o ${<:.c=.o}

all: 	${NAME}

${NAME}:	${OBJS} ft_printf.h
				ar -rsc ${NAME} ${OBJS}

clean:	
		rm -f ${OBJS}

fclean:	clean
		rm -f ${NAME}

re:	fclean all

.PHONY: all clean fclean re 
NAME = libftprintf.a

SRCS = ft_strlen.c ft_putstr.c ft_putnbr.c ft_putnbr_hexmin.c ft_putnbr_hexmaj.c \
				ft_putchar.c ft_putadress_hex.c ft_put_unsigned_nbr.c ft_printf.c

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
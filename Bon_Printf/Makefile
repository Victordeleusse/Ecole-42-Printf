NAME = libftprintf.a

SRCS = ft_strlen.c ft_putstr.c ft_putnbr.c ft_putnbr_hexmin.c ft_putnbr_hexmaj.c \
				ft_putchar.c ft_putadress_hex.c ft_put_unsigned_nbr.c ft_printf.c

OBJS = ${SRCS:.c=.o}
DEPS = ${SRCS:.c=.d}

CC = gcc -Wall -Werror -Wextra -I ./

%.o: %.c 
			${CC} -I. -MMD -c $< -o ${<:.c=.o}

all: 	${NAME}

${NAME}:	${OBJS}
				ar -rsc ${NAME} ${OBJS} 

clean:	
		rm -f ${OBJS} ${DEPS} 

fclean:	clean
		rm -f ${NAME}

-include $(DEPS)

re:	fclean all

.PHONY: all clean fclean re 
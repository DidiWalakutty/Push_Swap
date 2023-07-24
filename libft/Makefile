NAME = libft.a

SRCS =	ft_isdigit.c ft_strlen.c ft_putchar.c \
		ft_putstr.c ft_putendl.c ft_putstr_fd.c \
		
OBJ = ${SRCS:.c=.o}

OBJ_B = ${SRCS_B:.c=.o}

CC = gcc

CFLAGS = -Wall -Werror -Wextra

RM = rm -f

all: ${NAME}

AR = ar -rcs

${NAME}: ${OBJ}
		${AR} ${NAME} ${OBJ}

bonus:	${NAME} $(OBJ_B)
		${AR} $< ${OBJ_B}
test:
		./${NAME}

clean:
		${RM} ${OBJ}

fclean: clean
		${RM} ${NAME}

re: 	fclean $(NAME)

.PHONY: all clean fclean re
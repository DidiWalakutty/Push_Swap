# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: diwalaku <diwalaku@student.42.fr>            +#+                      #
#                                                    +#+                       #
#    Created: 2023/05/18 17:39:35 by diwalaku      #+#    #+#                  #
#    Updated: 2023/07/24 15:26:03 by diwalaku      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = 		push_swap

LIBFT = 	./libft/libft.a
LIBFT_FLAG = -I libft

SRCS =	main.c \
		parsing.c \
		utils.c \
		sort_utils.c \
		sorting.c \
		swap.c \
		push.c \
		rotate.c \
		reverse_rotate.c \
		error.c \
		
OBJ = ${SRCS:.c=.o}

CC = gcc

CFLAGS = -Wall -Werror -Wextra

all: ${NAME}

${NAME}: ${OBJ} ${LIBFT}
	${CC} -o $@ $^

%.o: %.c
	${CC} ${CFLAGS} -c -o $@ ${LIBFT_FLAG} $^
	
${LIBFT}:
	${MAKE} -C libft

clean:
		${RM} ${OBJ}
		${MAKE} -C libft clean

fclean: clean
		${RM} ${NAME}
		${MAKE} -C libft fclean

re:		fclean ${NAME}

visual:
		./push_swap_visualizer/build/bin/visualizer

.PHONY: all clean fclean re
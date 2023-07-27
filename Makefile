# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: diwalaku <diwalaku@student.42.fr>            +#+                      #
#                                                    +#+                       #
#    Created: 2023/05/18 17:39:35 by diwalaku      #+#    #+#                  #
#    Updated: 2023/07/27 19:24:27 by diwalaku      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = 		push_swap
OBJ_DIR =	obj
LIBFT_DIR = ./libft
LIBFT = 	$(LIBFT_DIR)/libft.a
LIBFT_FLAG = -I $(LIBFT_DIR)

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
		
OBJ = $(patsubst %.c, $(OBJ_DIR)/%.o, $(SRCS))

CC = gcc
CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) -o $@ $^
	
$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c -o $@ $(LIBFT_FLAG) $<

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)
	
clean:
		$(RM) -r $(OBJ_DIR)
		$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
		$(RM) $(NAME)
		$(MAKE) -C $(LIBFT_DIR) fclean

re:		fclean $(NAME)

visual:
		./push_swap_visualizer/build/bin/visualizer

.PHONY: all clean fclean re
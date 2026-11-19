# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mohfall <mohfall@student.42lausanne.ch>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/11/01 18:48:14 by mohfall           #+#    #+#              #
#    Updated: 2026/11/10 15:37:53 by mohfall          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC_DIR = src
INC_DIR = includes
OBJ_DIR = objs
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

INCLUDES = -I$(INC_DIR) -I$(LIBFT_DIR)
LDFLAGS = -L$(LIBFT_DIR) -lft

SRC_FILES = parse_args.c \
			 parse_flags.c \
			 validate_args.c \
			 sort_medium.c \
			 sort_small.c \
			 sort_adaptive.c \
			 sort_radix.c \
			 push.c \
			 swap.c \
			 rotate.c \
			 reverse_rotate.c \
			 stack_init.c \
			 stack_utils.c \
			 errors.c \
			 free_memory.c \
			 ft_atol.c \
			 indexation.c \
			 main.c \
			 bench.c \
			 print_bench.c

OBJS = $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))

vpath %.c $(SRC_DIR)/operations $(SRC_DIR)/parsing $(SRC_DIR)/sorting \
	$(SRC_DIR)/stack $(SRC_DIR)/utils $(SRC_DIR)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $(NAME)

$(OBJ_DIR)/%.o: %.c $(INC_DIR)/push_swap.h | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) clean

re: fclean all

.PHONY: all clean fclean re

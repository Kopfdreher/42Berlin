# --- Variables ---
NAME		= push_swap
CC			= cc
CFLAGS		= -Wall -Wextra -Werror

# Paths
LIBFT_DIR	= ./libft
LIBFT		= $(LIBFT_DIR/libft.a

# Include Paths
INCLUDES	= -.I -I$(LIBFT_DIR)

# Source files
SRCS = $(wildcard *.c)

# 
all: $(NAME)

gcc:
	gcc -o $(NAME) $(SRCS) libft.a -g

$(NAME):
	cc -o $(NAME) $(SRCS) libft.a

fclean:
	rm $(NAME)

re:
	fclean all

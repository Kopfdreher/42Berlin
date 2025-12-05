# |--- Variables --------------------------------|

NAME		= push_swap
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror

# Paths
LIBFT_DIR	= ./libft
LIBFT		= $(LIBFT_DIR)/libft.a

# Include Paths
INCLUDES	= -I. -I$(LIBFT_DIR)

# Source files
SRCS 		= $(addsuffix .c, helper input_check_num input_check_str move_path_finding move_reverse_rotate move_rotate move_table operation_push operation_reverse_rotate operation_rotate operation_swap_fts push_swap sort_dump sort_turk_to_a sort_turk_to_b)

# Object files
OBJS		= $(SRCS:.c=.o)

# |--- Rules ------------------------------------|

all: $(NAME)

# Main Traget
$(NAME): $(OBJS) $(LIBFT)
		$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) -L$(LIBFT_DIR) -lft -o $(NAME) -g

# Libft
$(LIBFT):
		@echo "|--- Building Libft ---|"
		@make -C $(LIBFT_DIR)

# Compiling .c to .o
%.o: %.c
		$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@ -g

# |--- Clean up ---------------------------------|

# Remove all Object-Files
clean:
		@rm -f $(OBJS)
		@make clean -C $(LIBFT_DIR)

# Remove all Object- and Archive-Files
fclean: clean
		@rm -f $(NAME)
		@make fclean -C $(LIBFT_DIR)

# Rebuild
re: fclean all

.PHONY: clean all re fclean

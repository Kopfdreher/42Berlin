# |--- Variables --------------------------------|

NAME		= so_long
CC			= cc
CFLAGS		= -Wall -Wextra -Werror -g -O3

# Colors
GREEN		= \033[0;32m
RESET		= \033[0m

# Paths
LIBFT_DIR	= ./libft
LIBFT		= $(LIBFT_DIR)/libft.a

MLX_DIR		= ./mlx_linux
MLX_LIB		= $(MLX_DIR)/libmlx_Linux.a

HEADERS		= so_long.h

# Includes & Linking
INCLUDES	= -I. -I$(LIBFT_DIR) -I$(MLX_DIR) -I/usr/include
LDFLAGS		= -L$(LIBFT_DIR) -lft \
			  -L$(MLX_DIR) -lmlx_Linux \
			  -L/usr/lib -lXext -lX11 -lm -lz

# Source files
SRCS 		= $(addsuffix .c, main)

# Object files
OBJS		= $(SRCS:.c=.o)

# |--- Rules ------------------------------------|

all: $(NAME)

# Main Traget
$(NAME): $(OBJS) $(LIBFT) $(MLX_LIB)
		@echo "$(GREEN)Linking $(NAME)...$(RESET)"
		@$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $(NAME)
		@echo "$(GREEN)$(NAME) created successfully!$(RESET)"

# Libft
$(LIBFT):
		@echo "$(GREEN)Building Libft...$(RESET)"
		@make -C $(LIBFT_DIR) > /dev/null

# MLX
$(MLX_LIB):
		@echo "$(GREEN)Building MiniLibX...$(RESET)"
		@make -C $(MLX_DIR) > /dev/null

# Compiling .c to .o
%.o: %.c $(HEADERS)
		@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# |--- Clean up ---------------------------------|

# Remove all Object-Files
clean:
		@echo "$(GREEN)Cleaning Objects...$(RESET)"
		@rm -f $(OBJS)
		@make clean -C $(LIBFT_DIR) > /dev/null
		@make clean -C $(MLX_DIR) > /dev/null

# Remove all Object- and Archive-Files
fclean: clean
		@echo "$(GREEN)Cleaning Executables...$(RESET)"
		@rm -f $(NAME)
		@make fclean -C $(LIBFT_DIR) > /dev/null
		@rm -f $(MLX_LIB)

# Rebuild
re: fclean all

B.PHONY: clean all re fclean

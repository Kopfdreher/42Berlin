# |--- Variables --------------------------------|

NAME		= so_long
CC			= cc
CFLAGS		= -Wall -Wextra -Werror -g -03

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
		@make -C $(LIBFT_DIR) > /dev/null 2>&1

# MLX
$(MLX_LIB):
		@echo "$(GREEN)Building MiniLibX...$(RESET)"
		@make -C $(MLX_DIR) > /dev/null 2>&1

# Compiling .c to .o
%.o: %.c $(HEADERS)
		@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# |--- Clean up ---------------------------------|

# Remove all Object-Files
clean:
		@echo "$(GREEN)Cleaning Objects...$(RESET)"
		@rm -f $(OBJS)
		@make clean -C $(LIBFT_DIR) > /dev/null 2>&1
		@make clean -C $(MLX_DIR) > /dev/null 2>&1

# Remove all Object- and Archive-Files
fclean: clean
		@echo "$(GREEN)Cleaning Executables...$(RESET)"
		@rm -f $(NAME)
		@make fclean -C $(LIBFT_DIR) > /dev/null 2>&1
		@make fclean -C $(MLX_DIR) > /dev/null 2>&1

# Rebuild
re: fclean all

.PHONY: clean all re fclean

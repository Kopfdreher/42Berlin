# |--- Variables --------------------------------|

NAME		= philo
CC			= cc
CFLAGS		= -Wall -Wextra -Werror -pthread -g

# Colors
GREEN		= \033[0;32m
BLUE		= \033[0;36m
RESET		= \033[0m

# Directories
SRC_DIR		= src
OBJ_DIR		= obj
INC_DIR		= includes

# Includes
HEADERS		= philo.h

# Source files
SRC_FILES	= $(addsuffix .c, main ft_atol parsing utils)
SRCS		= $(addprefix $(SRC_DIR)/, $(SRC_FILES))

# Object files
OBJS		= $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))

# |--- Rules ------------------------------------|

all: $(NAME)

# Main Traget
$(NAME): $(OBJS)
		@echo "$(BLUE)|--Linking $(NAME)------------------|$(RESET)"
		@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
		@echo "$(GREEN)|--$(NAME) created successfully!----|$(RESET)"

# Compiling .c to .o
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS)
		@mkdir -p $(OBJ_DIR)
		@$(CC) $(CFLAGS) -I $(INC_DIR) -c $< -o $@

# |--- Clean up ---------------------------------|

# Remove all Object-Files
clean:
		@echo "$(BLUE)|--Cleaning Objects-----------------|$(RESET)"
		@rm -rf $(OBJ_DIR)
		@echo "$(GREEN)|--Cleaned successfully!------------|$(RESET)"

# Remove all Object- and Archive-Files
fclean: clean
		@echo "$(BLUE)|--Cleaning Executable--------------|$(RESET)"
		@rm -f $(NAME)
		@echo "$(GREEN)|--Cleaned successfully!------------|$(RESET)"

# Rebuild
re: fclean all

.PHONY: clean all re fclean

NAME = libft.a

LIBFT = $(wildcard libft/*.c)

GNL = $(wildcard get_next_line/*.c)
	
PRINTF = $(wildcard printf/*.c)

SRCS = $(LIBFT) $(GNL) $(PRINTF)

OBJS = $(SRCS:%.c=%.o)

CC = cc -Wall -Werror -Wextra -fPIC

GCC = gcc -Wall -Werror -Wextra -fPIC -g

RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

%.o: %.c
	$(GCC) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

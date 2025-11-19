NAME = libft.a

LIBFT = $(wildcard libft/*.c)

GNL = $(wildcard get_next_line/*.c)
	
PRINTF = $(wildcard printf/*.c)

SRCS = $(LIBFT) $(GNL) $(PRINTF)

OBJS = $(SRCS:%.c=%.o)

CCFLAGS = cc -Wall -Werror -Wextra

RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

%.o: %.c
	$(CCFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

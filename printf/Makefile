NAME = libftprintf.a

SRC = $(addsuffix .c, ft_helper ft_printf put_char put_hex put_int put_string put_unsigned_int put_voidp)

OBJS := $(SRC:%.c=%.o)

CC = gcc

CCFLAGS = -Wall -Werror -Wextra

RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

%.o: $.c
	$(CC) $(CCFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

NAME = libft.a

SRCS = $(addsuffix .c, free_split ft_atoi ft_atol ft_bzero ft_calloc ft_isalnum ft_isalpha ft_isascii ft_isdigit ft_isprint ft_itoa ft_memchr ft_memcmp ft_memcpy ft_memmove ft_memset ft_putchar_fd ft_putendl_fd ft_putnbr_fd ft_putstr_fd ft_split ft_strchr ft_strdup ft_striteri ft_strjoin ft_strlcat ft_strlcpy ft_strlen ft_strmapi ft_strncmp ft_strnstr ft_strrchr ft_strtrim ft_substr ft_tolower ft_toupper)

BONUS = $(addsuffix .c, ft_lstadd_back ft_lstadd_front ft_lstclear ft_lstdelone ft_lstiter ft_lstlast ft_lstmap ft_lstnew ft_lstsize)

PRINTF = $(addsuffix .c, ft_helper ft_printf put_char put_hex put_int put_string put_unsigned_int)

GNL = $(addsuffix .c, get_next_line_bonus get_next_line_utils_bonus)
OBJS = ${SRCS:.c=.o}

OBJS_BONUS = ${BONUS:.c=.o}

OBJS_PRINTF = ${PRINTF:.c=.o}

CC = cc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror

.c.o:
	${CC} ${CFLAGS} -g -c $< -o ${<:.c=.o}

${NAME}: ${OBJS} ${OBJS_BONUS} ${OBJS_PRINTF}
	ar rcs ${NAME} ${OBJS} ${OBJS_BONUS} ${OBJS_PRINTF}

clean:
	${RM} ${OBJS} ${OBJS_BONUS} ${OBJS_PRINTF}

all: ${NAME}


fclean: clean
	${RM} ${NAME}

re: fclean all

NAME		= ex00

CC			= c++
CPPFLAGS	= -Wall -Werror -Wextra -std=c++98

INCS		= $(addsuffix .hpp, Zombie)

SRCS		= $(addsuffix .cpp, main Zombie newZombie randomChump)

OBJS		= $(SRCS:.cpp=.o)

RM			= rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CPPFLAGS) $(OBJS) -o $(NAME)

%.o : %.cpp $(INCS)
	$(CC) $(CPPFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

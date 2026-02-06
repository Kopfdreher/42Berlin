NAME		= ex03

CC			= c++
CPPFLAGS	= -Wall -Werror -Wextra -Wno-shadow -std=c++98

INCS		= $(addsuffix .hpp, ClapTrap ScavTrap FragTrap DiamondTrap)

SRCS		= $(addsuffix .cpp, main ClapTrap ScavTrap FragTrap DiamondTrap)

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

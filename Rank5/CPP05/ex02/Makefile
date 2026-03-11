NAME		= ex02

CC			= c++
CPPFLAGS	= -Wall -Werror -Wextra -std=c++98

INCS		= $(addsuffix .hpp, Bureaucrat AForm ShrubberyCreationForm\
			  RobotomyRequestForm PresidentialPardonForm)

SRCS		= $(addsuffix .cpp, main Bureaucrat AForm ShrubberyCreationForm\
			  RobotomyRequestForm PresidentialPardonForm)

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

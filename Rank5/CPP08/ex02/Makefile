NAME		= ex02

CXX			= c++
CXXFLAGS	= -Wall -Werror -Wextra -std=c++98

INCS		= $(addsuffix .hpp, MutantStack )\
			  $(addsuffix .tpp, MutantStack )

SRCS		= $(addsuffix .cpp, main )

OBJS		= $(SRCS:.cpp=.o)

RM			= rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

%.o : %.cpp $(INCS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

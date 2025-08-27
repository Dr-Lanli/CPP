NAME = ClapTrap

CXX = c++
CXXFLAGS = -std=c++98 -Wall -Wextra -Werror

SRCS = main.cpp ClapTrap.cpp
OBJS = $(SRCS:.cpp=.o)
INCLUDES = ClapTrap.hpp

all: $(NAME)
 
$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
 
clean:
	$(RM) $(OBJS)
 
fclean: clean
	$(RM) $(NAME)
 
re: fclean all

.PHONY: all clean fclean re
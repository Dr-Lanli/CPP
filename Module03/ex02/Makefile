NAME = FragTrap

CXX = c++
CXXFLAGS = -std=c++98 -Wall -Wextra -Werror

SRCS = main.cpp ScavTrap.cpp ClapTrap.cpp FragTrap.cpp
OBJS = $(SRCS:.cpp=.o)
INCLUDES = ScavTrap.hpp ClapTrap.hpp FragTrap.hpp

all: $(NAME)
 
$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
 
clean:
	$(RM) $(OBJS)
 
fclean: clean
	$(RM) $(NAME)
 
re: fclean all

.PHONY: all clean fclean re
NAME = Animal

CXX = c++
CXXFLAGS = -std=c++98 -Wall -Wextra -Werror

SRCS = main.cpp Animal.cpp Cat.cpp Dog.cpp WrongAnimal.cpp WrongCat.cpp
OBJS = $(SRCS:.cpp=.o)
INCLUDES = Animal.hpp Cat.hpp Dog.hpp WrongAnimal.hpp WrongCat.hpp

all: $(NAME)
 
$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
 
clean:
	$(RM) $(OBJS)
 
fclean: clean
	$(RM) $(NAME)
 
re: fclean all

.PHONY: all clean fclean re
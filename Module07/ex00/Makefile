NAME = whatever

CXX = c++
CXXFLAGS = -std=c++98 -Wall -Wextra -Werror

SRCS = main.cpp
OBJS = $(SRCS:.cpp=.o)
INCLUDES = whateverhpp

all: $(NAME)
 
$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
 
clean:
	$(RM) $(OBJS)
 
fclean: clean
	$(RM) $(NAME)
 
re: fclean all

.PHONY: all clean fclean re
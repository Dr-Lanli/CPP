NAME = identify

CXX = c++
CXXFLAGS = -std=c++98 -Wall -Wextra -Werror

SRCS = main.cpp Base.cpp A.cpp B.cpp C.cpp
OBJS = $(SRCS:.cpp=.o)
INCLUDES = Base.hpp A.hpp B.hpp C.hpp

all: $(NAME)
 
$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
 
clean:
	$(RM) $(OBJS)
 
fclean: clean
	$(RM) $(NAME)
 
re: fclean all

.PHONY: all clean fclean re
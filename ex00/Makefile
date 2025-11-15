NAME = bureaucrat

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = Bureaucrat.cpp main.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@echo "Linking $(NAME)..."
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
	@echo "$(NAME) created successfully!"

%.o: %.cpp
	@echo "Compiling $<..."
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@echo "Cleaning object files..."
	rm -f $(OBJS)

fclean: clean
	@echo "Removing $(NAME)..."
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

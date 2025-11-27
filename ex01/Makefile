NAME = form

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

# Dossier pour les fichiers objets
OBJ_DIR = obj

SRCS = Bureaucrat.cpp Form.cpp main.cpp

# Les objets vont dans le dossier obj/
OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.cpp=.o))

all: $(NAME)

# Créer le dossier obj s'il n'existe pas
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(NAME): $(OBJ_DIR) $(OBJS)
	@echo "Linking $(NAME)..."
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
	@echo "$(NAME) created successfully!"

# Règle pour compiler les .cpp en .o dans le dossier obj/
$(OBJ_DIR)/%.o: %.cpp
	@echo "Compiling $< -> $@..."
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@echo "Cleaning object files..."
	rm -rf $(OBJ_DIR)

fclean: clean
	@echo "Removing $(NAME)..."
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

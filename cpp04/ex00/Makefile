NAME	= bioExperiment.out
CXX		= c++
CXXFLAGS= -Wall -Wextra -Werror -std=c++98 -MMD -MP -pedantic
SRC		= main.cpp Animal.cpp Dog.cpp Cat.cpp WrongAnimal.cpp WrongCat.cpp
OBJ		= $(SRC:.cpp=.o)
DEP		= $(SRC:.cpp=.d)
RM 		= rm -f
SILENT 	= @

all: $(NAME)

$(NAME): $(OBJ)
	$(SILENT)$(CXX) $(OBJ) $(CXXFLAGS) -o $@
	@echo "░█████╗░██████╗░██████╗░░█████╗░░░██╗██╗"
	@echo "██╔══██╗██╔══██╗██╔══██╗██╔══██╗░██╔╝██║"
	@echo "██║░░╚═╝██████╔╝██████╔╝██║░░██║██╔╝░██║"
	@echo "██║░░██╗██╔═══╝░██╔═══╝░██║░░██║███████║"
	@echo "╚█████╔╝██║░░░░░██║░░░░░╚█████╔╝╚════██║"
	@echo "░╚════╝░╚═╝░░░░░╚═╝░░░░░░╚════╝░░░░░░╚═╝"

-include $(DEP)

%.o: %.cpp
	$(SILENT)$(CXX) $(CXXFLAGS) -c $< -o $@
debug:
	$(SILENT)$(MAKE) CXXFLAGS="$(CXXFLAGS) -g" re

valgrind: re
	valgrind --leak-check=full --show-leak-kinds=all \
	         --track-origins=yes  ./$(NAME)

run: all
	./$(NAME)

vtable: $(NAME)
	@echo "🔎 Dumping vtables from $(NAME):"
	@nm -C $(NAME) | grep vtable || echo "No vtables found!"



clean:
	$(SILENT)$(RM) $(OBJ) $(DEP)

fclean: clean
	$(SILENT)$(RM) $(NAME)

re: fclean all

.PHONY	: all clean fclean re
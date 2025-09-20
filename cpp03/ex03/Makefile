NAME	= clapTrap.out
CXX		= c++
CXXFLAGS= -Wall -Wextra -Werror -std=c++98 -MMD -MP -pedantic -Wshadow -Wno-shadow
SRC		= main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp DiamondTrap.cpp
OBJ		= $(SRC:.cpp=.o)
DEP		= $(SRC:.cpp=.d)
RM 		= rm -f
SILENT 	= @

all: $(NAME)

$(NAME): $(OBJ)
	$(SILENT)$(CXX) $(OBJ) $(CXXFLAGS) -o $@
	@echo "░█████╗░██████╗░██████╗░░█████╗░██████╗░"
	@echo "██╔══██╗██╔══██╗██╔══██╗██╔══██╗╚════██╗"
	@echo "██║░░╚═╝██████╔╝██████╔╝██║░░██║░█████╔╝"
	@echo "██║░░██╗██╔═══╝░██╔═══╝░██║░░██║░╚═══██╗"
	@echo "╚█████╔╝██║░░░░░██║░░░░░╚█████╔╝██████╔╝"
	@echo "░╚════╝░╚═╝░░░░░╚═╝░░░░░░╚════╝░╚═════╝░"

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

clean:
	$(SILENT)$(RM) $(OBJ) $(DEP)

fclean: clean
	$(SILENT)$(RM) $(NAME)

re: fclean all

.PHONY	: all clean fclean re
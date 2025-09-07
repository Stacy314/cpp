NAME	= clapTrap.out
CXX		= c++
CXXFLAGS= -Wall -Wextra -Werror -std=c++98 -MMD -MP -pedantic
SRC		= main.cpp ClapTrap.cpp
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

clean:
	$(SILENT)$(RM) $(OBJ) $(DEP)

fclean: clean
	$(SILENT)$(RM) $(NAME)

re: fclean all

.PHONY	: all clean fclean re
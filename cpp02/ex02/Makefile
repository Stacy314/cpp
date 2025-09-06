NAME	= fixed.out
CXX		= c++
CXXFLAGS= -Wall -Wextra -Werror -std=c++98 -MMD -MP
SRC		= main.cpp Fixed.cpp
OBJ		= $(SRC:.cpp=.o)
DEP		= $(SRC:.cpp=.d)
RM 		= rm -f
SILENT 	= @

all: $(NAME)

$(NAME): $(OBJ)
	$(SILENT)$(CXX) $(OBJ) $(CXXFLAGS) -o $@
	@echo "░█████╗░██████╗░██████╗░░█████╗░██████╗░"
	@echo "██╔══██╗██╔══██╗██╔══██╗██╔══██╗╚════██╗"
	@echo "██║░░╚═╝██████╔╝██████╔╝██║░░██║░░███╔═╝"
	@echo "██║░░██╗██╔═══╝░██╔═══╝░██║░░██║██╔══╝░░"
	@echo "╚█████╔╝██║░░░░░██║░░░░░╚█████╔╝███████╗"
	@echo "░╚════╝░╚═╝░░░░░╚═╝░░░░░░╚════╝░╚══════╝"

-include $(DEP)

%.o: %.cpp
	$(SILENT)$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	$(SILENT)$(RM) $(OBJ) $(DEP)

fclean: clean
	$(SILENT)$(RM) $(NAME)

re: fclean all

.PHONY	: all clean fclean re
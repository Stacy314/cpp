NAME	= zombie
CC		= c++
CFLAGS	= -Wall -Wextra -Werror -std=c++98 -MMD -MP
SRC		= main.cpp Fixed.cpp Point.cpp bsp.cpp
OBJ		= $(SRC:.cpp=.o)
DEP		= $(SRC:.cpp=.d)
RM 		= rm -f
SILENT 	= @

all: $(NAME)

$(NAME): $(OBJ)
	$(SILENT)$(CC) $(OBJ) $(CFLAGS) -o $@
	@echo "░█████╗░██████╗░██████╗░░█████╗░██████╗░"
	@echo "██╔══██╗██╔══██╗██╔══██╗██╔══██╗╚════██╗"
	@echo "██║░░╚═╝██████╔╝██████╔╝██║░░██║░░███╔═╝"
	@echo "██║░░██╗██╔═══╝░██╔═══╝░██║░░██║██╔══╝░░"
	@echo "╚█████╔╝██║░░░░░██║░░░░░╚█████╔╝███████╗"
	@echo "░╚════╝░╚═╝░░░░░╚═╝░░░░░░╚════╝░╚══════╝"

-include $(DEP)

%.o: %.cpp
	$(SILENT)$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(SILENT)$(RM) $(OBJ)

fclean:
	$(SILENT)$(RM) $(OBJ) $(NAME)

re: fclean all

.PHONY	: all clean fclean re
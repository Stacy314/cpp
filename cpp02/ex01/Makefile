NAME	= zombie
CC		= c++
CFLAGS	= -Wall -Wextra -Werror -g -std=c++98
SRC		= main.cpp Fixed.cpp
OBJ		= $(SRC:%.cpp=%.o)
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

%.o: %.cpp
	$(SILENT)$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(SILENT)$(RM) $(OBJ)

fclean:
	$(SILENT)$(RM) $(OBJ) $(NAME)

re: fclean all

.PHONY	: all clean fclean re
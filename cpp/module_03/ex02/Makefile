NAME		= ClapTrap
	
CC			= c++
FLAGS		= -Wall -Wextra -Werror -std=c++98

OBJDIR = .objects

FILES		= main ClapTrap ScavTrap FragTrap

SRC			= $(FILES:=.cpp)
OBJ			= $(addprefix $(OBJDIR)/, $(FILES:=.o))
HEADER		= ClapTrap.hpp ScavTrap.hpp FragTrap.hpp

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	@$(CC) $(OBJ) $(OPTS) -o $(NAME)

$(OBJDIR)/%.o: %.cpp $(HEADER)
	@mkdir -p $(dir $@)
	@$(CC) $(FLAGS) $(OPTS) -c $< -o $@

clean:
	rm -rf $(OBJDIR) $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
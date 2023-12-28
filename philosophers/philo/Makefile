NAME	=	philo
CC		=	gcc
CFLAGS	=	-g -Wall -Wextra -Werror -MMD -MP

SRC		=	main.c inits.c errors.c utils.c philo_death.c philo.c
OBJ		=	$(addprefix $(OBJ_DIR), $(SRC:.c=.o))
DEPS	=	$(addprefix $(DPS_DIR), $(SRC:.c=.d))

SRC_DIR	=	src/
OBJ_DIR	=	obj/
DPS_DIR	=	dps/
INCS	=	-I./includes/
LIB	=	-lpthread

all: make_dir $(NAME)

make_dir:
	@mkdir -p $(OBJ_DIR) $(DPS_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | make_dir
	@$(CC) $(CFLAGS) $(INCS) -c $< -o $@
	@mv $(basename $@).d $(DPS_DIR)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(INCS) $(OBJ) -o $(NAME) $(LIB)

clean:
	@rm -rf $(OBJ_DIR) $(DPS_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

-include $(DEPS)

.PHONY: all make_dir clean fclean re

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daraz <daraz@student.42prague.com>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/13 10:05:16 by daraz             #+#    #+#              #
#    Updated: 2023/11/11 15:59:27 by daraz            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
CC = cc
FLAGS = -g #-Wall -Werror -Wextra
OBJ = obj/main.o obj/utils.o
OBJ_DIR = obj
LIBFT = obj/libft/libft.o
LIBFT_DIR = src/libft
NAME_H = include/pipex.h

all: $(NAME) 

$(NAME): $(LIBFT) $(OBJ) $(NAME_H) 
	$(CC) $(OBJ) $(LIBFT) -o $(NAME)

obj/%.o: src/%.c
	$(CC) -g -Wall -Wextra -Werror -c $< -o $@

$(LIBFT): $(LIBFT_DIR)/*.c
	@if  [ ! -d obj/libft ]; then \
		mkdir -p obj/libft; \
	fi
	@make -C $(LIBFT_DIR)
	@cp $(LIBFT_DIR)/libft.a $(LIBFT)
	@make fclean -C $(LIBFT_DIR)

clean:
	@$(RM) $(OBJ) $(OBJ_M) $(LIBFT) rm -rf $(OBJ_DIR)

fclean: clean
	@$(RM) $(NAME)

re: clean all

.PHONY: all clean fclean re
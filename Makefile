# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jerasmus <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/14 15:37:16 by jerasmus          #+#    #+#              #
#    Updated: 2017/06/17 14:53:18 by lchimes          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = filler 

PATH_H = -I includes/

CFLAGS = -Wall -Werror -Wextra -g

SRC =	main.c		\
		read.c		\
		moves.c		\
		shave.c		\

OBJ =	main.o		\
		read.o		\
		moves.o		\
		shave.o		\

$(NAME):
	@make re -C libft/
	@clang $(PATH_H) $(CFLAGS) -o $(NAME) $(SRC) -L libft/ -lft

all: $(NAME)

clean: 
	@make -C libft/ clean
	@rm -f $(OBJ)

fclean: clean
	@make -C libft/ fclean
	@rm -f $(NAME)

re: fclean all

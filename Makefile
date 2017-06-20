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
		utilities.c \
		sectors.c   \
		t_left_b_right.c \
		t_right_b_left.c  \
		check_wall.c    \
	    build_walls.c   \
	    fill_corner.c  \

OBJ =	main.o		\
		read.o		\
		moves.o		\
		shave.o		\
		utilities.o \
		sectors.o   \
		t_left_b_right.o \
        t_right_b_left.o  \
        check_wall.o     \
        build_walls.o   \
        fill_corner.o  \

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

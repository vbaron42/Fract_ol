# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vbaron <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/04 16:55:00 by vbaron            #+#    #+#              #
#    Updated: 2016/11/23 05:28:55 by vbaron           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

##Recreer le header

NAME	=	fractol
FLAGS	=	-lmlx -framework OpenGL -framework AppKit
CC		=	gcc
SRC		=	main.c
OBJ		=	$(SRC:.c=.o)

all:		$(NAME)

$(NAME):
	cd libft/ && $(MAKE)
	$(CC) $(FLAGS) $(SRC) -L ./libft -lft -o $(NAME)
	cd libft/ && $(MAKE) fclean

%.o: %.c
	$(cc) $(FLAGS) -c $^ -o $@

norminette:
	norminette $(SRC)
	norminette fractol.h

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vbaron <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/14 16:31:35 by vbaron            #+#    #+#              #
#    Updated: 2016/12/17 03:47:59 by vbaron           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	fractol
FLAGS	=	-lmlx -framework OpenGL -framework AppKit
CC		=	gcc
SRC		=	main.c img.c event.c mandelbrot.c julia.c autre.c
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

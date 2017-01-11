# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vbaron <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/14 16:31:35 by vbaron            #+#    #+#              #
#    Updated: 2017/01/11 09:13:56 by vbaron           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	fractol
FLAGS	=	-lmlx -framework OpenGL -framework AppKit
CC		=	gcc
SRC		=	main.c img.c event.c color.c tools.c \
			mandelbrot.c julia.c sierpinski.c vision.c
OBJ		=	$(SRC:.c=.o)

all:		$(NAME)

$(NAME):
	@cd libft/ && $(MAKE)
	@$(CC) $(FLAGS) $(SRC) -L ./libft -lft -o $(NAME)
	@cd libft/ && $(MAKE) fclean
	@printf '\033[32m[ ✔ ] %s\n\033[0m' "Create Fractol"
%.o: %.c
	@$(cc) $(FLAGS) -c $^ -o $@

norminette:
	@norminette $(SRC)
	@norminette fractol.h

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebednar <ebednar@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/06 17:15:58 by ebednar           #+#    #+#              #
#    Updated: 2019/02/11 17:49:54 by ebednar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRC = 	main.c \
		keys.c \
		init_fr.c \
		calculation.c \
		draw.c \
		threads.c

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror -g

INCLUDES = -I includes -I libft

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft/
	gcc $(FLAGS) $(INCLUDES) -L libft/ -lft -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit $(SRC) -o $(NAME)

%.o: %.c
	gcc $(FLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -rf $(OBJ)
	make -C libft/ clean

fclean: clean
	rm -rf $(NAME)
	make -C libft/ fclean

re: fclean all

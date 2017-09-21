# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yribeiro <yribeiro@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/21 17:37:15 by yribeiro          #+#    #+#              #
#    Updated: 2017/09/21 17:41:00 by yribeiro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CFLAGS = -Wall -Wextra -Werror
SRC = parser.c ft_printf.c
OBJ = $(SRC:.c=.o)
LIBFT_H = -Ilibft/
LIBFT = libft/libft.a
MLX = -L /usr/local/lib -lmlx -lXext -lX11 -lm
MACMLX = -L/usr/local/lib/ -I/usr/local/include -lmlx -framework OpenGL -framework AppKit


all: $(NAME)

$(NAME):
	make -C libft/
	gcc $(CFLAGS) $(LIBFT_H) -c $(SRC)
	gcc $(CFLAGS) -o $(NAME) $(OBJ) -lm -L libft/ -lft -lmlx -framework OpenGL -framework AppKit
	#gcc $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT) $(MACLX)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
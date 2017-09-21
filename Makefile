# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yribeiro <yribeiro@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/21 17:37:15 by yribeiro          #+#    #+#              #
#    Updated: 2017/09/21 20:12:30 by yribeiro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_printf
CFLAGS = -Wall -Wextra -Werror
SRC = parser.c ft_printf.c
OBJ = $(SRC:.c=.o)
LIBFT_H = -Ilibft/
LIBFT = libft/libft.a


all: $(NAME)

$(NAME):
	make -C libft/
	gcc $(CFLAGS) $(LIBFT_H) -c $(SRC)
	gcc $(CFLAGS) -o $(NAME) $(OBJ) -lm -L libft/ -lft

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/21 17:37:15 by yribeiro          #+#    #+#              #
#    Updated: 2017/10/16 20:18:16 by anonymous        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = printf
#CFLAGS = -Wall -Wextra -Werror
SRC = parser.c ft_printf.c main.c specifier.c processes.c process_int.c process_string.c process_pointer.c
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
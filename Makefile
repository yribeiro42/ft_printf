# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yribeiro <yribeiro@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/21 17:37:15 by yribeiro          #+#    #+#              #
#    Updated: 2017/10/23 15:34:09 by yribeiro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = printf
#CFLAGS = -Wall -Wextra -Werror
SRC = parser.c ft_printf.c main.c specifier.c processes.c process_int.c process_string.c process_pointer.c
OBJ = $(SRC:.c=.o)
LIBFT_H = -Ilibft/
LIBFT = libft/libft.a


all: $(NAME)

%.o : %.c
	gcc $(CFLAGS) $(LIBFT_H) -c $?

$(NAME): $(OBJ)
	make -C libft/
	gcc $(CFLAGS) -o $(NAME) $^ -lm -L libft/ -lft

clean:
	make clean -C libft/
	rm -rf $(OBJ)

fclean: clean
	make fclean -C libft/
	rm -rf $(NAME)

re: fclean all
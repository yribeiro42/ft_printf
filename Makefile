# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yribeiro <yribeiro@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/21 17:37:15 by yribeiro          #+#    #+#              #
#    Updated: 2017/10/25 16:16:36 by yribeiro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#NAME = libftprintf.a
NAME = printf

#CFLAGS = -Wall -Wextra -Werror
SRC = parser.c ft_printf.c main.c specifier.c processes.c process_int.c process_string.c \
 process_pointer.c process_octal.c process_hex.c process_unsigned.c process_wchar.c \
 process_character.c
OBJ = $(SRC:.c=.o)
LIBFT_H = -Ilibft/
LIBFT = libft/libft.a
LIB_O = $(addprefix ./libft/, *.o)


all: $(NAME)

%.o : %.c
	gcc $(CFLAGS) $(LIBFT_H) -c $?

$(NAME): $(OBJ)
	make -C libft/
	#ar rc libftprintf.a $(OBJ) $(LIB_O)
	gcc $(CFLAGS) -o $(NAME) $^ -lm -L libft/ -lft

clean:
	make clean -C libft/
	rm -rf $(OBJ)

fclean: clean
	make fclean -C libft/
	rm -rf $(NAME)

re: fclean all

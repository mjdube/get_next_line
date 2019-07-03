# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdube <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/03 17:47:48 by mdube             #+#    #+#              #
#    Updated: 2019/07/03 18:04:17 by mdube            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = get_next_line.c

OBJ = get_next_line.o main.o

all: $(NAME)

$(NAME):
	@clang -Wall -Werror -Wextra -I libft/includes -o get_next_line.o -c get_next_line.c
	@clang -Wall -Werror -Wextra -I libft/includes -0 main.o -c main.c
	@clang -o test_gnl main.o get_next_line.o libft/includes -L libft/ -lft

clean:
	rm -f $(OBJ)

fclean:
	rm -f $(NAME)

re: fclean all

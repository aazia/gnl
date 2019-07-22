# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: azkeever <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/02 10:36:43 by azkeever          #+#    #+#              #
#    Updated: 2019/01/08 14:01:14 by azkeever         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = gnl
HEADER = get_next_line.c tests/gnl7_3.c
LIBRARY = libft/libft.a
SOURCE = get_next_line.h

all: $(NAME)

$(NAME):
	gcc -Wall -Werror -Wextra $(HEADER) $(LIBRARY)

clean: 
	rm -f *.o *.swp *~ *.gch

fclean: clean
	rm -f $(NAME) a.out

re: fclean all


# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nhamid <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/18 11:42:51 by nhamid            #+#    #+#              #
#    Updated: 2019/03/18 11:55:32 by nhamid           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
all : $(NAME)
$(NAME) :
	make -C libft
	gcc -c *.c -pthread
	gcc -Wall -Wextra -Werror -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit  *.o libft/libft.a -o $(NAME)
clean :
	rm -rf *.o
	make -C libft clean
fclean : clean
	rm -rf $(NAME)
	make -C libft fclean
re : fclean all
	make -C libft re

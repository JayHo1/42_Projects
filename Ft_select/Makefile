#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cho <cho@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/09/16 16:17:30 by cho               #+#    #+#              #
#    Updated: 2015/09/16 16:17:43 by cho              ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = ft_select

FLAGS 	= -Wall -Wextra -Werror
LIB		= -L /usr/lib -ltermcap
CC 		= gcc

SRC			= main.c \
				term.c \
				list.c \
				get_list.c \
				element.c \
				select.c \

OBJ 		= $(SRC:.c=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): 
	@make -C libft/
	$(CC) $(FLAGS) -c $(SRC) -I libft/
	$(CC) $(FLAGS) $(LIB) -o $(NAME) $(OBJ) libft/libft.a

clean: 
	@make -C libft clean
	$(RM) $(OBJ)

fclean: clean
	@make -C libft fclean
	$(RM) $(NAME)

re: fclean all

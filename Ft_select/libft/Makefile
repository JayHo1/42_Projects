#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cho <cho@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/08 11:04:34 by cho               #+#    #+#              #
#    Updated: 2014/11/13 11:46:19 by cho              ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libft.a

SRC = ft_putchar.c ft_putstr.c ft_putnbr.c ft_strlen.c ft_strdup.c \
            ft_atoi.c ft_strcpy.c ft_strncpy.c ft_strcat.c ft_tolower.c \
            ft_toupper.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isprint.c \
            ft_isascii.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c \
            ft_memmove.c ft_memchr.c ft_memcmp.c ft_strcmp.c ft_strncmp.c \
            ft_strstr.c ft_strnstr.c ft_strchr.c ft_strrchr.c ft_strlcat.c \
            ft_memdel.c ft_memalloc.c ft_strnew.c ft_strdel.c ft_strclr.c \
            ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c ft_strequ.c \
            ft_strnequ.c ft_strsub.c ft_strjoin.c ft_strtrim.c \
            ft_putendl.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
            ft_putnbr_fd.c ft_strncat.c ft_itoa.c ft_strsplit.c \
			ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c \

FO = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror

CC = gcc

all : $(NAME)

$(NAME) :
			$(CC) -c $(FLAGS) $(SRC)
			ar rc $(NAME) $(FO)
			ranlib $(NAME)

clean :
		/bin/rm -f $(FO)

fclean : clean
		/bin/rm -f $(NAME)

re : fclean all
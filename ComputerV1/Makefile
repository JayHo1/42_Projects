NAME = computor

FLAGS = -Wall -Wextra -Werror

CC = gcc

SRC = main2.c \
		calcul.c \
		check.c \
		computer.c \
		f_error.c \
		display.c \


OBJ = $(SRC:.c=.o)

RM = rm -f

.PHONY: all, clean, fclean, re

all:
	@make $(NAME)

$(NAME): 
	@make -C libft/
	$(CC) $(FLAGS) -c $(SRC) -I libft/
	$(CC) $(FLAGS) -o $(NAME) $(OBJ) libft/libft.a

clean:
	@make -C libft/ clean
	@$(RM) $(OBJ)

fclean:
	@make -C libft/ fclean
	@$(RM) $(NAME)

re: fclean all
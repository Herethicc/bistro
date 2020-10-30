##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## makefile
##

SRC     =       $(wildcard *.c)

OBJ     =       $(SRC:.c=.o)

NAME    =       bistro_matic

all:    $(NAME)

$(NAME):        $(OBJ)
	make -C lib/my/ all
	gcc -o $(NAME) $(OBJ) -L lib/my/ -lmy -g3

clean:
	make -C lib/my/ clean
	rm -f $(OBJ)
	rm -f $(NAME)

fclean: clean
	rm -f $(NAME)

re:	fclean all

##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## create a Makefile
##

SRC	=	$(wildcard *.c)

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -c *.c
	ar rc libmy.a $(OBJ)
	cp libmy.a ../
	cp my.h ../../include

clean:
	rm -f $(OBJ)
	rm -f libmy.a
	rm -f ../libmy.a

fclean: clean
	rm -f $(NAME)

re:	fclean all

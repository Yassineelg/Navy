##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

SRC	=	compiles/main.c	\
		compiles/connexion_2.c	\
		compiles/connexion.c	\
		compiles/errors.c	\
		compiles/tiret_h.c

NAME	=	navy

all:	$(NAME)

$(NAME):
	make re -C lib/my/
	gcc $(SRC) -L. -lmy -o $(NAME)

clean:
	rm -rf *~ \#*\# .\#*

fclean:
	rm -f $(NAME)

re:	fclean all clean
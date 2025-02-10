##
## EPITECH PROJECT, 2024
## Makefile Root
## File description:
## MakeFile dans le fichier root
##

NAME = my_sh
DEBUG = -g
CFLAGS += -g -Wall -Wextra -W -Iinclude -Ilib/include

SRC =	src/main.c\

OBJ  	=	 $(SRC:.c=.o)


all: 	$(NAME)

$(NAME):	$(OBJ)
		make -C ./lib
		gcc -o $(NAME) $(OBJ) -L./lib -lm

clean || clear:
		$(MAKE) -C lib clean
		rm -f $(OBJ)

fclean:
		rm -f $(NAME) debug $(OBJ) libmy.a

re:
		$(MAKE) fclean
		$(MAKE) all

debug: 	$(DEBUG)

$(DEBUG):	$(OBJ)
		make -C ./lib
		gcc -g $(CFLAGS) main.c -o debug $(OBJ) libmy.a

redebug:
		$(MAKE) fclean
		$(MAKE) debug

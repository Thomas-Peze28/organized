##
## EPITECH PROJECT, 2024
## makefile pong seb
## File description:
## makfile
##

SRC	=	main.c	\
		my_add_node.c	\

NAME	=	organized

OBJ	=	$(SRC:.c=.o)

CFLAGS = -I./include -L./lib/my -lmy -Wall -Wextra

all: build_lib $(OBJ)
	gcc -o $(NAME) $(OBJ) $(CFLAGS) libshell/libshell.a

build_lib:
		make -C ./lib/my/

clean_lib:
		make clean -C ./lib/my/

clean: clean_lib
	rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re: fclean all

run: re
	./$(NAME)

.PHONY: all fclean clean re

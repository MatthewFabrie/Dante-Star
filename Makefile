##
## EPITECH PROJECT, 2020
## Dante_Star
## File description:
## makefile
##

CC				=	gcc
CFLAGS			=	-W -Wall -Wextra
CPPFLAGS		=	-I./include
LDFLAGS			=	-L./ -lmy

SRC				=	$(wildcard src/*.c)

OBJ				=	$(SRC:.c=.o)

NAME			=	Dante_Star

all				: $(NAME)

$(NAME)			: 
				make -C solver
				make -C generator

clean			:
				$(MAKE) -C solver $@
				$(MAKE) -C generator $@
				$(RM) solver/libmy.a
				$(RM) generator/libmy.a

fclean			:	clean

re				:	fclean all

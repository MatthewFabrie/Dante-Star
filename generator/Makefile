##
## EPITECH PROJECT, 2020
## generator
## File description:
## makefile
##

CC				=	gcc
CFLAGS			=	-W -Wall -Wextra
CPPFLAGS		=	-I./include
LDFLAGS			=	-L./ -lmy

SRC				=	$(wildcard src/*.c)

OBJ				=	$(SRC:.c=.o)

NAME			=	generator

all				: $(NAME)

$(NAME)			: lib/my/libmy.a $(OBJ)
				@echo "\033[1;37mBinary Compilation...\033[0m"
				$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)
				@echo "\033[1;34m[OK] \033[1;32mCompilated binary\033[0m\033[1;31m [$(NAME)]\033[0m"

lib/my/libmy.a	:
				@echo "\033[1;37mLib Compilation...\033[0m"
				@$(MAKE) -C lib/my all
				@echo "\033[1;34m[OK] \033[1;32mLib Compilated\033[0m"

clean			:
				$(RM) $(OBJ)
				$(RM) $(NAME)
				$(RM) src/*~
				$(RM) *~
				$(RM) /#*#/
				$(MAKE) -C lib/my $@

fclean			:	clean
				$(MAKE) -C lib/my $@

re				:	fclean all

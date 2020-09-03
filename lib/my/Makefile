##
## EPITECH PROJECT, 2019
## day10
## File description:
## Makefile
##

SRC	=	my_getnbr.c		\
		my_isneg.c		\
		my_putchar.c		\
		my_putstr.c		\
		my_revstr.c		\
		my_showstr.c		\
		my_strcpy.c \
		my_strlen.c		\
		my_atoi.c 		\
		my_itoa.c 		\
		my_itoa_n.c 		\
		my_swap.c \
		my_strcmp.c

NAME	= libmy.a

OBJ	= $(SRC:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	cp $(NAME) ./../
	cp my.h ./../../include/

clean:
	rm -rf $(OBJ)

fclean:		clean
	rm -rf $(NAME)

re: fclean all

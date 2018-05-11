##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile
##

CC	=	gcc

RM	=	rm -f

SRC	=	src/my_putstr.c		\
		src/pixel.c		\
		src/window.c		\
		src/event.c		\
		src/background.c	\
		src/mouse.c		\
		src/init.c		\
		src/death.c		\
		src/text.c		\
		src/duck.c		\
		src/duck2.c		\
		src/main2.c

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-I./include

CFLAGS	+=	-Wall -Wextra

LDFLAGS	=	-lc_graph_prog

NAME	=	my_hunter

all:		$(NAME) clean

$(NAME):	$(OBJ)
		$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:		all clean fclean re

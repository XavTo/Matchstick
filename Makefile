##
## EPITECH PROJECT, 2020
## makefile
## File description:
## compil
##

SRCS =	bsmatchstick.c \
		check_getline.c \
		my_while.c \
		ia.c \
		select_ia.c \
		bin.c \
		bin_split.c \
		howtowin.c \
		howtowin2.c \
		check_win.c \

OBJS = $(SRCS:.c=.o)

NAME = matchstick

all : $(NAME)

$(NAME) :
		make -C lib/my
		gcc -g -o $(NAME) $(SRCS) -L lib/ -lmy -I include
		make x -C lib/my

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

x : re
	clear
	./$(NAME)
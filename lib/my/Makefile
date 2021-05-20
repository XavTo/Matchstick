##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## First Makefile
##

SRCS =	my_strcapitalize.c \
	my_check_even.c \
	my_revstr.c \
	my_str_isupper.c \
	my_compute_power_rec.c \
	my_showmem.c \
	my_strlen.c \
	my_compute_square_root.c \
	my_strlowcase.c \
	my_find_prime_sup.c \
	my_sort_int_array.c \
	my_strncat.c \
	my_getnbr.c \
	my_strcat.c \
	my_strncmp.c \
	my_strcmp.c \
	my_strcpy.c \
	my_strncpy.c \
	my_isneg.c \
	my_strdup.c \
	my_strstr.c \
	my_is_prime.c \
	my_str_isalpha.c \
	my_strupcase.c \
	my_putchar.c \
	my_str_islower.c \
	my_swap.c \
	my_put_nbr.c \
	my_str_isnum.c \
	my_putstr.c \
	my_str_isprintable.c \
	my_printf.c \
	my_printf2.c \
	my_convert_binary.c \
	my_convert_hexa.c \
	my_convert_octa_base.c \
	my_put_nbr2.c \
	my_put_short.c \

OBJS = $(SRCS:.c=.o)
NAME =  libmy.a
CP = cp $(NAME) ../
MYH = cp my.h ../../include

all : $(NAME)

$(NAME) : $(OBJS)
	ar rc $(NAME) $(OBJS) && $(CP) && $(MYH)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f ${NAME}

allclean : fclean
	cd ../ && rm -f $(NAME) && cd ../ && rm -rf include

re : fclean all

x : fclean
	cd ../ && rm -f $(NAME)

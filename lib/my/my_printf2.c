/*
** EPITECH PROJECT, 2020
** my print
** File description:
** 2 normes
*/

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int my_putstr(char const *str);

int my_printf(char const *format, ...);

char *binary_create(int a, int ben, int j, char *binary);

int my_put_nbr2(int nb, int *p_ret);

void my_putchar(char c);

int my_octa_convert(unsigned int ben, int *p_ret);

int my_strlen(char *str);

int my_put_short(short nb, int *p_ret);

int my_exec_convert(unsigned int ben, int *p_ret);

int my_exec_maj_short(unsigned short ben, int *p_ret);

int my_exec_convert_short(unsigned short ben, int *p_ret);

int my_display_add(unsigned long long ben, int *p_ret);

int my_convert_octa_base(va_list args, char *stock, int *p_ret);

int display_norme2(va_list args, char *stock, int b, int *p_ret);

int my_short_or_long(va_list args, char *stock, int b, int *p_ret)
{
    int hd = 0;

    if (stock[b] == 'h' && stock[b - 1] == '%') {
        if (stock[b + 1] == 'd' || stock[b + 1] == 'i' || stock[b + 1] == 'u') {
            hd = va_arg(args, unsigned int);
            my_put_short(hd, p_ret);
        }
        if (stock[b + 1] == 'x')
            hd = va_arg(args, unsigned int), my_exec_convert_short(hd, p_ret);
        if (stock[b + 1] == 'X')
            hd = va_arg(args, unsigned int), my_exec_maj_short(hd, p_ret);
        b = b + 2;
    }
    return (b);
}

int display_let(va_list args, char *stock, int b, int *p_ret)
{
    char c;

    if (stock[b] == 'c' && stock[b - 1] == '%')
            c = va_arg(args, int), my_putchar(c), b++, (*p_ret)++;
        if (stock[b] == 'S' && stock[b - 1] == '%')
            my_convert_octa_base(args, stock, p_ret), b++;
        b = display_norme2(args, stock, b, p_ret);
    return (b);
}

char *my_format_hash(int *b_ret, char *s, int b, int *p_ret)
{
    if (s[b + 2] == 'o') {
        my_putchar('0'), (*p_ret)++;
        s[b] = '$', s[b + 1] = '%';
    }
    if (s[b + 2] == 'x') {
        my_putstr("0x"), (*p_ret)++, (*p_ret)++;
        s[b] = '$', s[b + 1] = '%';
    }
    if (s[b + 2] == 'X') {
        my_putstr("0X"), (*p_ret)++, (*p_ret)++;
        s[b] = '$', s[b + 1] = '%';
    }
    else
        s[b] = '$', s[b + 1] = '%', (*b_ret)++;
    return (s);
}

char *my_formnumber(int *b_ret, char *s, int b, int *p_ret)
{
    int h = 0;
    int c = 0;

    h = s[b + 1] - 48;
    if (h > 2) {
        while (c != h - 2) {
            my_putchar(' ');
            c++;
            (*p_ret)++;
        }
    }
    s[b + 1] = '%', (*b_ret)++;
    return (s);
}

char *my_form(int *b_ret, char *s, int b, int *p_ret)
{
    if (s[b] == '%' && s[b + 1] == '+') {
            my_putchar('+'), (*p_ret)++;
        s[b + 1] = '%', s[b] = '$', (*b_ret)++;
    }
    if (s[b] == '%' && s[b + 1] == ' ') {
        b++;
        while (s[b] == ' ')
            b++, (*b_ret)++;
        my_putchar(' '), (*p_ret)++;
        s[b - 1] = '%';
    }
    if (s[b] == '%' && s[b + 1] >= '0' && s[b + 1] <= '9')
        s = my_formnumber(b_ret, s, b, p_ret);
    if (s[b] == '%' && s[b + 1] == '-') {
        s[b + 1] = '%', s[b] == '$', (*b_ret)++;
    }
    if (s[b] == '%' && s[b + 1] == '#')
        my_format_hash(b_ret, s, b, p_ret);
    return (s);
}

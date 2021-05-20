/*
** EPITECH PROJECT, 2020
** my print
** File description:
** display
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

int my_convert_hexa_base(va_list args, char *stock, int *p_ret);

int my_convert_hexa_base2(va_list args, char *stock, int *p_ret);

char *my_form(int *b_ret, char *s, int b, int *p_ret);

int my_short_or_long(va_list args, char *stock, int b, int *p_ret);

int display_let(va_list args, char *stock, int b, int *p_ret);

int my_convert_octa_base(va_list args, char *stock, int *p_ret);

int my_convert_binary_base(va_list args, char *stock, int *p_ret);

int display_base(va_list args, char *stock, int b, int *p_ret)
{
    unsigned long long p = 0;

    if (stock[b] == 'p' && stock[b - 1] == '%') {
        p = va_arg(args, unsigned long long);
        my_putstr("0x"), (*p_ret)++, (*p_ret)++;
        my_display_add(p, p_ret), b++;
    }
    if (stock[b] == 'X' && stock[b - 1] == '%')
        my_convert_hexa_base2(args, stock, p_ret), b++;
    if (stock[b] == 'o' && stock[b - 1]  == '%')
        p = va_arg(args, unsigned int), my_octa_convert(p, p_ret), b++;
    if (stock[b] == 'b' && stock[b - 1] == '%')
        my_convert_binary_base(args, stock, p_ret), b++;
    if (stock[b] == 'x' && stock[b - 1] == '%')
        my_convert_hexa_base(args, stock, p_ret), b++;
    return (b);
}

int display_norme2(va_list args, char *stock, int b, int *p_ret)
{
    short hd = 0;
    char *string;
    int numb = 0;

    if (stock[b] == 's' && stock[b - 1] == '%') {
        string = va_arg(args, char *), my_putstr(string), b++;
        (*p_ret) = (*p_ret) + (my_strlen(string));
    }
    b = my_short_or_long(args, stock, b, p_ret);
    if ((stock[b] == 'd' || stock[b] == 'i' || stock[b] == 'u')
        && stock[b - 1] == '%' || (stock[b] == 'l'
        && stock[b + 1] == 'd' && stock[b - 1] == '%')) {
        if (stock[b] == 'l')
            b++;
        numb = va_arg(args, int), my_put_nbr2(numb, p_ret), b++;
    }
    b = display_base(args, stock, b, p_ret);
    return (b);
}

int display_norme(va_list args, char *s, int b, int ret)
{
    int *p_ret = &ret;
    int *b_ret = &b;

    while (s[b] != '\0') {
        b = display_let(args, s, b, p_ret), s = my_form(b_ret, s, b, p_ret);
        while (s[b] == '%' && s[b + 1] == '%')
            my_putchar('%'), b++, s[b] = '$', b++, (*p_ret)++;
        if (s[b] != '%' && s[b] != '\n') {
            if (s[b - 1] == '%' && s[b] != 'd' && s[b] != 'c' && s[b] != 's'
            && s[b] != 'h' && s[b] != 'S' && s[b] != 'x'
            && s[b] != 'b' && s[b] != 'p' && s[b] != 'o'
            && s[b] != 'i' && s[b] != 'u' && s[b] != 'X' && s[b - 2] != '%')
                my_putchar('%'), (*p_ret)++;
            if (s[b] == '\0') {break;}
            else {my_putchar(s[b]), (*p_ret)++;}
        }
        if (s[b] == '\n') {my_putchar('\n'), (*p_ret)++;}
        b++;
    }
    return (ret);
}

int my_create_stock(char *stock, char const *format, int i, va_list args)
{
    int a = 0;
    int c = 0;
    int ret;
    int z = 0;
    int b = 0;
    int *b_ret = &b;

    while (format[i] != '\0') {
        stock[i] = format[i];
        i++;
    }
    stock[i] = '\0';
    ret = display_norme(args, stock, b, z);
    return (ret);
}

int my_printf(char const *format, ...)
{
    int i = 0;
    int ret = 0;
    char *stock;
    va_list args;
    int a = 0;

    va_start(args, format);
    while (format[i] != '\0') {
        i++;
    }
    stock = malloc(sizeof(char) * (i + 1));
    i = 0;
    ret = my_create_stock(stock, format, i, args);
    va_end(args);
    return (ret);
}
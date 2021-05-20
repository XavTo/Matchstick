/*
** EPITECH PROJECT, 2020
** convert base
** File description:
** hexa
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

int my_display_add(unsigned long long ben, int *p_ret)
{
    int res = 0;
    int i = 1;
    int *stock = malloc(sizeof(int) * 50);

    stock[0] = 'f';
    while (ben > 15) {
        res = ben % 16;
        ben = ben / 16;
        stock[i] = res, i++, res = 0;
    }
    res = ben % 16;
    stock[i] = res;
    while (stock[i] != 'f') {
        if (stock[i] > 9)
            my_putchar(stock[i] + 87), (*p_ret)++;
        if (stock[i] < 10)
            my_putchar(stock[i] + 48), (*p_ret)++;
        i--;
    }
    free(stock);
}

int my_exec_maj(unsigned int ben, int *p_ret)
{
    int res = 0;
    int i = 1;
    int *stock = malloc(sizeof(int) * 50);

    stock[0] = 'f';
    while (ben > 15) {
        res = ben % 16;
        ben = ben / 16;
        stock[i] = res, i++, res = 0;
    }
    res = ben % 16;
    stock[i] = res;
    while (stock[i] != 'f') {
        if (stock[i] > 9)
            my_putchar(stock[i] + 55), (*p_ret)++;
        if (stock[i] < 10)
            my_putchar(stock[i] + 48), (*p_ret)++;
        i--;
    }
    free(stock);
}

int my_exec_convert(unsigned int ben, int *p_ret)
{
    int res = 0;
    int i = 1;
    int *stock = malloc(sizeof(int) * 50);

    stock[0] = 'f';
    while (ben > 15) {
        res = ben % 16;
        ben = ben / 16;
        stock[i] = res, i++, res = 0;
    }
    res = ben % 16;
    stock[i] = res;
    while (stock[i] != 'f') {
        if (stock[i] > 9)
            my_putchar(stock[i] + 87), (*p_ret)++;
        if (stock[i] < 10)
            my_putchar(stock[i] + 48), (*p_ret)++;
        i--;
    }
    free(stock);
}

int my_convert_hexa_base(va_list args, char *stock, int *p_ret)
{
    int ben = va_arg(args, unsigned int);

    my_exec_convert(ben, p_ret);
    return (0);
}

int my_convert_hexa_base2(va_list args, char *stock, int *p_ret)
{
    int ben = va_arg(args, unsigned int);

    my_exec_maj(ben, p_ret);
    return (0);
}

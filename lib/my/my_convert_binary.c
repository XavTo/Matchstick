/*
** EPITECH PROJECT, 2020
** convert base
** File description:
** binary
*/

#include <stdarg.h>
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

char *binary_create(int a, int ben, int j, char *binary)
{
    int h = 0;

    while (a > 0) {
        h = ben;
        ben = ben - a;
        if (ben >= 0)
            binary[j] = '1', j++, a = a / 2;
        else {
            a = a / 2;
            binary[j] = '0', j++, ben = h;
        }
    }
    return (binary);
}

int my_convert_binary_base(va_list args, char *stock, int *p_ret)
{
    int ben = va_arg(args, int);
    int h;
    int j = 0;
    int a = 1;
    char *binary = malloc(sizeof(char) * (ben * 8));

    while (a < ben) {
        if (a >= 1073741824)
            return (0);
        a = a * 2;
    }
    binary = binary_create(a, ben, j, binary);
    while (binary[j] == '0')
        j++;
    while (binary[j] != '\0')
        my_putchar(binary[j]), j++, (*p_ret)++;
    free(binary);
    return (0);
}

int my_exec_maj_short(unsigned short ben, int *p_ret)
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

int my_exec_convert_short(unsigned short ben, int *p_ret)
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
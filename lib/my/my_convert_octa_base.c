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

int my_octa_convert(unsigned int ben, int *p_ret)
{
    int *save = malloc(sizeof(int) * 50);
    int i = 0;

    if (ben < 10)
        my_putchar('0'), (*p_ret)++;
    if (ben < 100)
        my_putchar('0'), (*p_ret)++;
    save[i] = 'f', i++;
    save[i] = ben % 8, i++;
    while (ben > 1) {
        ben = ben / 8;
        save[i] = ben % 8, i++;
    }
    i--;
    while (save[i] == 0)
        i--;
    while (save[i] != 'f')
        my_putchar(save[i] + 48), i--, (*p_ret)++;
    free(save);
}

int my_convert_octa_base(va_list args, char *stock, int *p_ret)
{
    int i = 0;
    char *string = va_arg(args, char *);
    while (string[i] != '\0') {
        if (string[i] < 32 || string[i] >= 127) {
            my_putchar('\\'), (*p_ret)++;
            my_octa_convert(string[i], p_ret);
            i++;
        }
        else {
            my_putchar(string[i]), (*p_ret)++;
            i++;
        }
    }
    return (0);
}
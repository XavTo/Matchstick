/*
** EPITECH PROJECT, 2020
** my put
** File description:
** short
*/

#include <unistd.h>

void my_putchar(char c);

int my_put_short(short nb, int *p_ret)
{
    if ((nb >= 32767) || (nb <= -32768)) {
        if (nb == -32768)
            write(1, "-32768", 6);
        if (nb == 32767)
            write(1, "32767", 5);
        return (0);
    }
    if (nb >= 0 && nb <= 9)
        my_putchar(nb + 48), (*p_ret)++;
    else if (nb < 0) {
        my_putchar('-'), (*p_ret)++;
        my_put_short(nb * (-1), p_ret);
    }
    else {
        my_put_short(nb / 10, p_ret);
        my_put_short(nb % 10, p_ret);
    }
    return (0);
}

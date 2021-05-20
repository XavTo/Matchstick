/*
** EPITECH PROJECT, 2020
** my_put_nbr
** File description:
** test
*/

#include <unistd.h>

void my_putchar(char c);

int my_put_nbr2(int nb, int *p_ret);

int my_put_nbr2(int nb, int *p_ret)
{
    if ((nb >= 2147483647) || (nb <= -2147483648)) {
        if (nb == -2147483648)
            write(1, "-2147483648", 11);
        if (nb == 2147483647)
            write(1, "2147483647", 10);
        return (0);
    }
    if (nb >= 0 && nb <= 9)
        my_putchar(nb + 48), (*p_ret)++;
    else if (nb < 0) {
        my_putchar('-'), (*p_ret)++;
        my_put_nbr2(nb * (-1), p_ret);
    }
    else {
        my_put_nbr2(nb / 10, p_ret);
        my_put_nbr2(nb % 10, p_ret);
    }
    return (0);
}

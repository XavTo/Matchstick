/*
** EPITECH PROJECT, 2020
** my_put_nbr
** File description:
** test
*/

#include <unistd.h>

void my_putchar(char c);

int my_put_nbr(int nb);

int my_put_nbr(int nb)
{
    if ((nb >= 2147483647) || (nb <= -2147483648)) {
        if (nb == -2147483648)
            write(1, "-2147483648", 11);
        if (nb == 2147483647)
            write(1, "2147483647", 10);
        return (0);
    }
    if (nb >= 0 && nb <= 9)
        my_putchar(nb + 48);
    else if (nb < 0) {
        my_putchar('-');
        my_put_nbr(nb * (-1));
    }
    else {
        my_put_nbr(nb / 10);
        my_put_nbr(nb % 10);
    }
    return (0);
}

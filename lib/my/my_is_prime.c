/*
** EPITECH PROJECT, 2020
** my_is_prime
** File description:
** nombre premier
*/

int my_is_prime(int nb)
{
    int i = 2;

    if (nb <= 1)
        return (0);
    if (nb <= 3 || nb <= 2)
        return (1);
    while (i <= nb / i) {
        if (nb % i == 0)
            return (0);
        i++;
    }
    return (1);
}

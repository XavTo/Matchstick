/*
** EPITECH PROJECT, 2020
** my_find_is_prime
** File description:
** nombre premier
*/

int my_is_prime(int nb);

int my_find_prime_sup(int nb)
{
    int i = nb;

    while (i >= nb)
    {
        if (my_is_prime(i))
            return (i);
        i++;
    }
    return (nb);
}

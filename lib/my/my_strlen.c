/*
** EPITECH PROJECT, 2020
** my_strlen
** File description:
** compteur
*/

int my_strlen(char const *str)
{
    int c;

    c = 0;
    while (str[c] != '\0')
        c++;
    return (c);
}

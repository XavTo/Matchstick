/*
** EPITECH PROJECT, 2020
** my_strdup
** File description:
** copy fonction
*/

#include <stdlib.h>

char *my_strdup(char const *src)
{
    int i = 0;
    char *dest;

    while (src[i] != '\0')
        i++;
    dest = malloc(sizeof(char) * (i + 1));
    i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    return (dest);
}

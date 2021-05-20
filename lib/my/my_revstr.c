/*
** EPITECH PROJECT, 2020
** my_revstr
** File description:
** copy fonction
*/

#include <stdio.h>

char *my_revstr(char *str)
{
    int i = 0;
    int e = 0;
    int a = 0;
    char swap;

    while (str[i] != '\0')
        i++;
    i--;
    e = i / 2;
    while (a != e) {
        swap = str[a];
        str[a] = str[i];
        str[i] = swap;
        i--;
        a++;
    }
    return (str);
}

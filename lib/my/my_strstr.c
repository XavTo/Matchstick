/*
** EPITECH PROJECT, 2020
** my_strstr
** File description:
** copy fonction
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int my_strlen2(char const *str)
{
    int i = 0;

    while (str[i] != '\0')
        i++;
    return (i);
}

char *my_strstr(char *str, char const *to_find)
{
    int i = 0;
    int a = 0;
    int c = 0;
    int b = my_strlen2(to_find);

    if (to_find[0] == '\0')
        return (str);
    while (str[i] != '\0') {
        if (to_find[a] == str[i])
            a++;
        if (to_find[a] == '\0')
            return (&str[i - (b - 1)]);
        i++;
    }
    return (NULL);
}

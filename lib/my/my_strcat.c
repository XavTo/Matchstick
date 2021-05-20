/*
** EPITECH PROJECT, 2020
** my_strcat
** File description:
** copy fonction
*/

char *my_strcat(char *dest, char const *src)
{
    int i = 0;
    int a = 0;

    while (dest[i] != '\0') {
        i++;
    }
    while (src[a] != '\0') {
        dest[i] = src[a];
        a++;
        i++;
    }
    return (dest);
}

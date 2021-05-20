/*
** EPITECH PROJECT, 2020
** my_strcat
** File description:
** copy fonction
*/

char *my_strncat(char *dest, char const *src, int nb)
{
    int i = 0;
    int a = 0;

    while (dest[i] != '\0') {
        i++;
    }
    while (src[a] != '\0' && a < nb) {
        dest[i] = src[a];
        a++;
        i++;
    }
    dest[i] = '\0';
    return (dest);
}

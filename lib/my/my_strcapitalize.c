/*
** EPITECH PROJECT, 2020
** my_strcapitalize
** File description:
** mettre en maj
*/

int check_norme(char *str, int i, int c)
{
    if (i == 0 && str[i] >= 'a' && str[i] <= 'z') {
        str[i] = str[i] - 32;
        i++;
        c = 0;
    }
    return (c);
}

char *my_strcapitalize(char *str)
{
    int i = 0;
    int c = 0;

    if (str[0] >= 'a' && str[0] <= 'z')
        str[0] = str[0] - 32;
    while (str[i] != '\0') {
        c = 1;
        c = check_norme(str, i, c);
        if ((str[i - 1] == ' ' || str[i - 1] == '+' || str[i - 1] == '-')
            && (str[i] >= 'a' && str[i] <= 'z') && c == 1) {
            str[i] = str[i] - 32;
            c = 2;
        }
        if (str[i] >= 'A' && str[i] <= 'Z' && c == 1 && i != 0)
            str[i] = str[i] + 32;
        i++;
    }
    return (str);
}

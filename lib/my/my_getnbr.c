/*
** EPITECH PROJECT, 2020
** azea
** File description:
** aze
*/

#include <unistd.h>

int check_end(char *str, int i, long long n, int b)
{
    if (n == 2147483648 && b == 1) {
        if (!(str[i + 1] >= '0' && str [i + 1] <= '9'))
            return (-2147483648);
    }
    if ((n / 10) > 2147483647 && (n / 10 ) != 2147483648)
        return (0);
    if (!(str[i + 1] >= '0' && str [i + 1] <= '9')) {
        n = n / 10;
        if (b == 1)
            n = n * -1;
        return (n);
    }
    return (n);
}

long long norme_check(char *str, int i, long long n)
{
    n = str[i] + n - '0';
    n = n * 10;
    return (n);
}

int check_ifeven(char *str, int b, int i)
{
    while ((str[i - 1] == '-') || (str[i - 1] == '+') && (i - 1) >= 0) {
        if (str[i - 1] == '+')
            i--;
        else {
            b++;
            i--;
        }
    }
    if ((b % 2) == 0)
        return (0);
    return (1);
}

long long calcul(char *str, int b, long long n, int a)
{
    for (int i = 0 ; str[i] != '\0' ; i++) {
        while (!(str[i] >= '0' && str[i] <= '9'))
            i++;
        b = check_ifeven(str, b, i);
        if (str[i] >= '0' && str[i] <= '9')
            n = norme_check(str, i, n);
        if (n == 21474836480 && b == 0)
            return (0);
        n = check_end(str, i, n, b);
        if (n == -2147483648)
            return (-2147483648);
        if (a > 11 || n == -1)
            return (0);
        if (!(str[i + 1] >= '0' && str[i + 1] <= '9'))
            return (n);
        a++;
    }
    return (0);
}

int my_getnbr(char *str)
{
    long long n = 0;
    int b = 0;
    int a = 0;

    if (str[0] == '-' && str[1] == '1' && str[2] == '\0')
        return (-1);
    n = calcul(str, b, n, a);
    return (n);
}

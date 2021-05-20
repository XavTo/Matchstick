/*
** EPITECH PROJECT, 2020
** tre
** File description:
** tre
*/

void my_sort_int_array(int *tab, int size)
{
    int i = 0;
    int swap = 0;

    while (i != size) {
        if (i > 0 && tab[i - 1] > tab[i]) {
            swap = tab[i];
            tab[i] = tab[i - 1];
            tab[i - 1] = swap;
            i = 0;
        }
        i++;
    }
}

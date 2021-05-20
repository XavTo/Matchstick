/*
** EPITECH PROJECT, 2021
** my sokoban
** File description:
** bootstrap
*/

#include "matchstick.h"

int check_win(game_t *game)
{
    int y = 0;
    int x = 0;
    int count_pipe = 0;

    while (game->board[y] != NULL) {
        while (game->board[y][x] != '\0') {
            count_pipe = split_pipe(game, count_pipe, x, y), x++;
        }
        y++, x = 0;
    }
    if (count_pipe <= 0)
        return (2);
}

void display_double_tab(char **str, int limit)
{
    int i = 0;
    int k = 0;

    while (k != limit * 2 + 1) my_printf("*"), k++;
    my_printf("\n");
    while (str[i] != NULL) {
        my_printf("%s\n", str[i]);
        i++;
    }
    k = 0;
    while (k != limit * 2 + 1) my_printf("*"), k++;
    my_printf("\n");
}

int test_str(char *str)
{
    int i = 0;
    int count = 0;

    while (str[i] != '\0') {
        if (str[i] >= '0' && str[i] <= '9')
            count++;
        if ((!(str[i] >= '0' && str[i] <= '9'))
            && str[i] != '\n')
            return (1);
        i++;
    }
    if (count == 0) return (1);
    return (0);
}

int check_line(game_t *game, int line, char *str, int *p)
{
    if (line >= game->limit || line < 0) {
        my_printf("Error: this line is out of range\n");
        my_game(game, 0, p);
        return (-1);
    }
    return (0);
}

int check_max_pipe(char **board, int nb_matches, char *str, int max)
{
    int i = 0;
    int count_pipe = 0;
    int y = my_getnbr(str) - 1;
    while (board[y][i] != '\0') {
        if (board[y][i] == '|') count_pipe++;
        i++;
    }
    if (nb_matches > max) {
        my_printf("Error: you cannot remove more than %d matches per turn\n",
        max);
        return (1);
    }
    if (nb_matches == 0) {
        my_printf("Error: you have to remove at least one match\n");
        return (1);
    }
    if (count_pipe < nb_matches) {
        my_printf("Error: not enough matches on this line\n");
        return (1);
    } return (0);
}
/*
** EPITECH PROJECT, 2021
** my sokoban
** File description:
** bootstrap
*/

#include "matchstick.h"

char **chnage_board(int line, int nb_matches, char **board, int limit)
{
    int i = 0;
    int max = 0;
    int count_pipe = 0;

    while (board[line][max] != '\0') max++;
    while (count_pipe != nb_matches) {
        if (i > limit * 2 + 1) return (0);
        if (board[line][max] == '|')
            board[line][max] = ' ', count_pipe++;
        max--;
    }
    return (board);
}

int my_count_nb(int nb, int *count)
{
    if (nb >= 0 && nb <= 9)
        (*count)++;
    else if (nb < 0) {
        my_count_nb(nb * (-1), count);
    }
    else {
        my_count_nb(nb / 10, count);
        my_count_nb(nb % 10, count);
    }
}

int *my_convert_binary(int *bin, int count_pipe)
{
    int more = 1;
    int i = 7;
    int save = count_pipe;
    int *stock = malloc(sizeof(int) * 9);

    bin = malloc(sizeof(int) * 9);
    stock[0] = 0, stock[1] = 0, stock[2] = 0, stock[3] = 0, stock[4] = 0;
    stock[5] = 0, stock[6] = 0, stock[7] = 0, stock[8] = -1;
    bin[0] = 0, bin[1] = 0, bin[2] = 0, bin[3] = 0, bin[4] = 0;
    bin[5] = 0, bin[6] = 0, bin[7] = 0, bin[8] = -1;
    while (save > 0) {
        stock[i] = save % 2;
        save = save / 2;
        i--;
    }
    i = 0, save = 0;
    while (stock[i] != -1) bin[save] = stock[i], i++, save++;
    free(stock);
    return (bin);
}

int *create_bin_split(int **bin, int *stock)
{
    int i = 0;
    int u = 0;
    int s = 0;
    int verif = 0;

    stock = malloc(sizeof(int) * 9);
    while (1) {
        stock[s] = 0;
        while (bin[i] != NULL)
            create_bin_split_branching(bin[i][u], &stock, s, &verif), i++;
        if (verif == 0) break;
        u++, verif = 0, i = 0, s++;
    }
    verif = 0, u = 0, stock[s] = -1, i = 0;
    while (u < s) verif = 10 * verif + stock[u], u++;
    my_count_nb(verif, &i);
    stock = malloc(sizeof(int) * i + 3), stock[i] = -1, s = 0;
    while (i >= 0) stock[i - 1] = verif % 10, verif /= 10, i--;
    return (stock);
}

int *create_bin(game_t *game, int *score)
{
    int i = 0;
    int x = 0;
    int y = 0;
    int u = 0;
    int count_pipe = 0;
    int **bin = malloc(sizeof(int *) * game->limit + 3);

    while (game->board[y] != NULL) {
        while (game->board[y][x] != '\0') {
            count_pipe = split_pipe(game, count_pipe, x, y), x++;
        }
        bin[i] = my_convert_binary(bin[i], count_pipe);
        y++, x = 0, count_pipe = 0, i++;
    }
    bin[i] = NULL, i = 0;
    score = create_bin_split(bin, score);
    return (score);
}
/*
** EPITECH PROJECT, 2021
** my sokoban
** File description:
** bootstrap
*/

#include "matchstick.h"

int clear_board(char **board)
{
    int i = 0;

    while (board[i] != NULL) {
        free(board[i]);
        i++;
    }
    free(board);
    return (0);
}

int split_pipe(game_t *game, int count_pipe, int x, int y)
{
    if (game->board[y][x] == '|') {
        count_pipe++;
    }
    return (count_pipe);
}

int *take_full_line_split(game_t *game, int *count_pipe, int *x, int y)
{
    if (game->board[y][*x] == '|')
        count_pipe[0]++, count_pipe[1] = y;
    (*x)++;
    return (count_pipe);
}

int create_bin_split_branching(int bin, int **stock, int s, int *verif)
{
    if (bin != -1)
        (*stock)[s] = (*stock)[s] + bin, (*verif)++;
    return (0);
}

int number_line_pipe_split(char **board, int y, int x, int *count_pipe)
{
    while (board[y][x] != '\0') {
        if (board[y][x] == '|') {
            (*count_pipe)++;
            return (1);
        }
        x++;
    }
    return (0);
}
/*
** EPITECH PROJECT, 2021
** my sokoban
** File description:
** bootstrap
*/

#include "matchstick.h"

int find_max_pipe(game_t *gcp, int line, int match)
{
    int i = 0;
    int count_pipe = 0;

    while (gcp->board[line][i] != '\0') {
        if (gcp->board[line][i] == '|') count_pipe++;
        i++;
    }
    if (match > count_pipe)
        return (1);
    return (0);
}

int count_total_pipe(char **board)
{
    int y = 0;
    int x = 0;
    int count_pipe = 0;

    while (board[y] != NULL) {
        while (board[y][x] != '\0') {
            if (board[y][x] == '|') count_pipe++;
            x++;
        }
        y++, x = 0;
    }
    return (count_pipe);
}

int count_nb_pipe(char **board, int *line)
{
    int y = 0;
    int x = 0;
    int count_pipe = 0;

    while (board[y] != NULL) {
        while (board[y][x] != '\0') {
            if (board[y][x] == '|')
                count_pipe++, *line = y;
            x++;
        }
        y++, x = 0;
    }
    if (count_pipe == 1) return (-1);
    return (count_pipe);
}

int count_pipe_line(char **board, int line)
{
    int y = line;
    int x = 0;
    int count_pipe = 0;

    while (board[y][x] != '\0') {
        if (board[y][x] == '|') count_pipe++;
        x++;
    }
    return (count_pipe);
}

int random_ia(game_t *game, int *line, int *match)
{
    int r = 0;

    while (game->board[r] != NULL) {
        if (count_pipe_line(game->board, r) == 1) {
            *line = r, *match = 1;
            return (0);
        }
        r++;
    }
    return (0);
}
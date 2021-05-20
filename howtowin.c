/*
** EPITECH PROJECT, 2021
** my sokoban
** File description:
** bootstrap
*/

#include "matchstick.h"

int take_line_split(game_t *game, int y, int *x, int *count_pipe)
{
    if (game->board[y][*x] == '|' && *count_pipe <= game->max_pipe)
        (*count_pipe)++;
    (*x)++;
}

int take_line(game_t *game, int *line, int *match, int where)
{
    int y = 0;
    int x = 0;
    int count_pipe = 0;
    int save = 0;
    int keep = 0;

    while (game->board[y] != NULL) {
        while (game->board[y][x] != '\0') {
            take_line_split(game, y, &x, &count_pipe);
        }
        if (count_pipe > keep)
            keep = count_pipe, save = y;
        y++, x = 0, count_pipe = 0;
    }
    *match = keep - 1, *line = save;
}

int take_full_line(game_t *game, int *line, int *match)
{
    int y = 0;
    int x = 0;
    int *count_pipe = malloc(sizeof(int) * 2);
    int *other = malloc(sizeof(int) * 2);

    count_pipe[0] = 0, count_pipe[1] = 0, other[0] = 0, other[1] = 0;
    while (game->board[y] != NULL) {
        while (game->board[y][x] != '\0') {
            count_pipe = take_full_line_split(game, count_pipe, &x, y);
        }
        if (count_pipe[0] != 0 && other[0] == 0)
            other[0] = count_pipe[0], other[1] = y, count_pipe[0] = 0;
        x = 0, y++;
    }
    *match = split_take_line(line, game, other, count_pipe);
    free(count_pipe), free(other);
}

int leave_one_line(game_t *game, int *line, int *match)
{
    int y = 0;
    int x = 0;
    int count_pipe = 0;

    while (game->board[y] != NULL) {
        while (game->board[y][x] != '\0') {
            count_pipe = split_pipe(game, count_pipe, x, y), x++;
        }
        if (count_pipe != 0) break;
        x = 0, y++, count_pipe = 0;
    }
    *line = y;
    if (count_pipe - 1 <= game->max_pipe) *match = count_pipe - 1;
    else *match = 1;
    return (0);
}

int find_best_way(game_t *game, int pipe, int *match, int *line)
{
    if (number_line_pipe(game->board) >= 3)
        take_line(game, line, match, 0);
    else if (number_line_pipe(game->board) == 2)
        take_full_line(game, line, match);
    else
        leave_one_line(game, line, match);
    return (0);
}
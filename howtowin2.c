/*
** EPITECH PROJECT, 2021
** my sokoban
** File description:
** bootstrap
*/

#include "matchstick.h"

int number_line_pipe(char **board)
{
    int y = 0;
    int x = 0;
    int count_pipe = 0;

    while (board[y] != NULL) {
        number_line_pipe_split(board, y, x, &count_pipe);
        y++, x = 0;
    }
    return (count_pipe);
}

int left_line(char **board, int line)
{
    int x = 0;
    int ret = 0;

    while (board[line][x] != '\0') {
        x++;
    }
    return (ret);
}

int split_take_line2(int *line, game_t *game, int *other, int *count)
{
    int match = 0;

    if (other[0] == 1) {
        if (count[0] <= game->max_pipe) {
            match = count[0], *line = count[1];
            return (match);
        }
        if (count[0] > game->max_pipe) {
            match = other[0], *line = other[1];
            return (match);
        }
    }
    if (other[0] == 2) {
        match = 1, *line = count[1];
        return (match);
    }
    if (count[0] == 2) {
        match = 1, *line = other[1];
        return (match);
    }
}

int split_line_sup(int *line, game_t *game, int *other, int *count)
{
    int match = 0;
    if (count[0] - game->max_pipe <= 0 && other[0] > game->max_pipe + 1) {
        while (count[0] - match != 0) match++;
        *line = count[1];
        return (match);
    }
    if (other[0] - game->max_pipe <= 0 && count[0] > game->max_pipe + 1) {
        while (other[0] - match != 0) match++;
        *line = other[1];
        return (match);}
    if (count[0] - game->max_pipe <= 2 && other[0] <= game->max_pipe) {
        while (count[0] - match != 2) match++;
        *line = count[1];
        return (match);}
    if (other[0] - game->max_pipe <= 2 && count[0] <= game->max_pipe) {
        while (other[0] - match != 2) match++;
        *line = other[1];
        return (match);
    }match = 1, *line = other[1];
    return (match);
}

int split_take_line(int *line, game_t *game, int *other, int *count)
{
    int i = 0;
    int match = 0;

    if (count[0] == 2 && other[0] == 2) {
        match = 1, *line = other[1];
        return (match);
    }
    if (count[0] > 2 && other[0] > 2) {
        match = split_line_sup(line, game, other, count);
        return (match);
    }
    if (count[0] == 1) {
        if (other[0] <= game->max_pipe) match = other[0], *line = other[1];
        if (other[0] > game->max_pipe) match = count[0], *line = count[1];
        return (match);
    }
    match = split_take_line2(line, game, other, count);
    return (match);
}
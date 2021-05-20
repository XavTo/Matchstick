/*
** EPITECH PROJECT, 2021
** my sokoban
** File description:
** bootstrap
*/

#include "matchstick.h"

char **copy_board(game_t *game, game_t *gcp)
{
    int i = 0;
    int x = 0;
    int y = 0;
    char **copy;

    copy = malloc(sizeof(char *) * game->limit + 1);
    copy[game->limit] = NULL;
    while (i != game->limit)
        copy[i] = malloc(sizeof(char) * game->limit * 2 + 3), i++;
    while (game->board[y] != NULL) {
        while (game->board[y][x] != '\0') {
            copy[y][x] = game->board[y][x];
            x++;
        }
        copy[y][x] = '\0';
        y++, x = 0;
    }
    gcp->limit = game->limit, gcp->max_pipe = game->max_pipe;
    return (copy);
}

int my_leave(game_t *game, int ret)
{
    int p = 0;

    if (ret == -1) {
        my_printf("\nYour turn:\n");
        my_game(game, 0, &p);
    }
    else
        return (ret);
}

int recup_match(game_t *game, int err, char *line, int *p)
{
    char *match = NULL;
    size_t buffsize = 0;
    if (know_if_win(game, p) == 1) return (-5);
    if (game->ret == 1 || game->ret == 2) return (0);
    my_putstr("Matches: "), err = getline(&match, &buffsize, stdin);
    if (err == -1 || match[my_strlen(match) - 1] != '\n') return (-1);
    if (test_str(match) == 1) {
        my_printf("Error: invalid input (positive number expected)\n");
        my_game(game, 0, p);
        return (0);
    }
    if (check_max_pipe(
        game->board, my_getnbr(match), line, game->max_pipe) == 0) {
        my_printf("Player removed %d match(es) from line %d\n",
        my_getnbr(match), my_getnbr(line));
        game->board = print_board(
            my_getnbr(line) - 1, my_getnbr(match), game->board, game->limit);
        return (my_getnbr(match));
    } else my_game(game, 0, p);
    return (-1);
}

int split_my_game(game_t *game, int match, int *p, char *line)
{
    int err = 0;

    if (game->ret == 1 || game->ret == 2) return (0);
    if (check_line(game, (my_getnbr(line) - 1), line, p) == -1)
        return (-1);
    match = recup_match(game, err, line, p);
    if (game->ret == 1 || game->ret == 2) return (0);
    if (check_win(game) >= 1) {
        my_printf("You lost, too bad...\n"), game->ret = 2;
        return (2);
    }
    if (know_if_win(game, p) == 1) return (1);
    if (match == -5) return (1);
    if (match == -1) return (-1);
    ia(game, match);
    return (0);
}

int my_game(game_t *game, int err, int *p)
{
    size_t buffsize = 0;
    int match = 0;
    int ret = 0;
    char *line = NULL;
    while (1) {
        if (game->ret == 1 || game->ret == 2) return (0);
        if (know_if_win(game, p) == 1) return (1);
        my_putstr("Line: "), err = getline(&line, &buffsize, stdin);
        if (err == -1 || line[my_strlen(line) - 1] != '\n') return (0);
        if (err == 1 || test_str(line) == 1) {
            my_printf("Error: invalid input (positive number expected)\n");
            my_game(game, 0, p);
            return (0);
        }
        ret = split_my_game(game, match, p, line);
        if (game->ret == 1 || game->ret == 2) return (0);
        if (ret == -1) return (0);
        if (know_if_win(game, p) == 1) return (1);
        my_printf("\nYour turn:\n");
    }
}
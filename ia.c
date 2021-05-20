/*
** EPITECH PROJECT, 2021
** my sokoban
** File description:
** bootstrap
*/

#include "matchstick.h"

int score_pair(int *score, game_t *gcp, game_t *game)
{
    int i = 0;

    while (score[i] != -1) {
        if (score[i] % 2 != 0)
            return (1);
        i++;
    }
    return (0);
}

int select_pipe(game_t *game, game_t *gcp, int s, int *line)
{
    int match = gcp->max_pipe;
    int count = 0;
    int *score = create_bin(game, score);
    *line = game->limit - 1;
    while (score_pair(score, gcp, game) == 1) {
        gcp->board = copy_board(game, gcp);
        while (find_max_pipe(gcp, *line, match) == 1) {
            match--;
            if (match == 0)
                (*line)--, match = game->max_pipe;
            if (*line < 0) return (-1);
        } gcp->board = chnage_board(*line, match, gcp->board, game->limit);
        score = create_bin(gcp, score), count++;
        if (score_pair(score, gcp, game) == 0) break;
        match--;
        if (match == 0)
            match = game->max_pipe, (*line)--;
        if (*line < 0) return (-1);
    }
    return (match);
}

int find_pipe(int *line, int *match, int *score, game_t *game)
{
    int i = 0;
    int s = 0;
    int pipe = 0;
    int count_pipe = 0;
    game_t gcp;

    if (count_total_pipe(game->board) <= game->max_pipe * 2
        || number_line_pipe(game->board) <= 2) {
        pipe = count_total_pipe(game->board);
        find_best_way(game, pipe, match, line);
        return (0);
    }
    gcp.board = copy_board(game, &gcp);
    *match = select_pipe(game, &gcp, s, line);
    if (*match == -1) take_line(game, line, match, 1);
    return (0);
}

int ia(game_t *game, int j_match)
{
    int line = 0;
    int match = 0;
    int c = 0;
    int *score = create_bin(game, score);

    if (count_nb_pipe(game->board, &line) == -1) {
        if (match <= 0) match = 1;
        my_printf("\nAI's turn...\n");
        my_printf("AI removed %d match(es) from line %d\n",
        match, line + 1);
        game->board = print_board(line, 1, game->board, game->limit);
        return (0);
    }
    line = 0, find_pipe(&line, &match, score, game);
    if (match <= 0) match = 1;
    my_printf("\nAI's turn...\n");
    my_printf("AI removed %d match(es) from line %d\n", match, line + 1);
    game->board = print_board(line, match, game->board, game->limit), c = 0;
    score = create_bin(game, score);
    return (0);
}
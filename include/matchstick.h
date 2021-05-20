/*
** EPITECH PROJECT, 2020
** my.h
** File description:
** fichier h prototypes
*/

#ifndef matchstick_h
#define matchstick_h

#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "my.h"

typedef struct {
    int limit;
    int max_pipe;
    char **board;
    int ret;
} game_t;

/* create and display tab */
void display_double_tab(char **str, int limit);
char **print_board(int line, int nb_matches, char **board, int limit);
char **print_game_board(char **board, int size);
char **chnage_board(int line, int nb_matches, char **board, int limit);
char **copy_board(game_t *game, game_t *gcp);
int *take_full_line_split(game_t *game, int *count_pipe, int *x, int y);
/*                        */

/* check if input user is good */
int check_line(game_t *game, int line, char *str, int *p);
int check_max_pipe(char **board, int nb_matches, char *str, int max);
int test_str(char *str);
int count_pipe_line(char **board, int line);
int count_nb_pipe(char **board, int *line);
int count_total_pipe(char **board);
int find_max_pipe(game_t *gcp, int line, int match);
int number_line_pipe(char **board);
int my_check_is_ec(char *str);
int number_line_pipe_split(char **board, int y, int x, int *count_pipe);
/*                             */

/* games rule */
int my_game(game_t *game, int err, int *p);
int my_leave(game_t *game, int ret);
int check_win(game_t *game);
int split_pipe(game_t *game, int count_pipe, int x, int y);
int know_if_win(game_t *game, int *p);
int clear_board(char **board);
/*            */

/* IA fonction */
int ia(game_t *game, int j_match);
int ia_match(game_t *game, int line, int j_match, int match);
int *create_bin(game_t *game, int *score);
int create_bin_branching(game_t *game, int *count_pipe, int *x, int y);
int create_bin_split_branching(int bin, int **stock, int s, int *verif);
int random_ia(game_t *game, int *line, int *match);
int find_best_way(game_t *game, int pipe, int *match, int *line);
int take_line(game_t *game, int *match, int *line, int where);
int split_take_line(int *line, game_t *game, int *other, int *count);
/*             */
#endif
/*
** EPITECH PROJECT, 2021
** my sokoban
** File description:
** bootstrap
*/

#include "matchstick.h"

char **split_create_board(int i, char **board, int stock, int max)
{
    int create = 1;
    int stick = 0;

    i = i - 2;
    while (i != -1) {
        while (stick != stock / 2)
            board[i][create] = ' ', create++, stick++;
        while (create != max - (stock / 2))
            create++;
        while (board[i][create] != '*')
            board[i][create] = ' ', create++;
        stock += 2, stick = 0, create = 1, i--;
    }
    return (board);
}

char **create_board(char **board, int size)
{
    int i = 0;
    int stock = 2;
    int create = 1;

    board = malloc(sizeof(char *) * size + 1);
    board[size] = NULL;
    while (i != size) board[i] = malloc(sizeof(char) * size * 2 + 3), i++;
    i = 0;
    while (i != size) {
        board[i][0] = '*';
        while (create != size * 2) board[i][create] = '|', create++;
        board[i][create] = '*', board[i][create + 1] = '\0', i++, create = 1;
    }
    board = split_create_board(i, board, stock, size * 2);
    return (board);
}

char **print_game_board(char **board, int size)
{
    board = create_board(board, size);
    display_double_tab(board, size);
    return (board);
}

char **print_board(int line, int nb_matches, char **board, int limit)
{
    int i = 0;
    int max = 0;
    int count_pipe = 0;

    while (board[line][max] != '\0') max++;
    while (count_pipe != nb_matches) {
        if (board[line][max] == '|')
            board[line][max] = ' ', count_pipe++;
        max--;
    }
    display_double_tab(board, limit);
    return (board);
}

int main(int ac, char **av)
{
    game_t game;
    int err = 0;

    if (ac != 3) return (84);
    if (test_str(av[1]) == 1 || test_str(av[2]) == 1) return (84);
    game.ret = 0;
    game.limit = my_getnbr(av[1]);
    game.max_pipe = my_getnbr(av[2]);
    if (game.limit >= 100 || game.limit <= 1)
        return (84);
    game.board = print_game_board(game.board, game.limit);
    err = my_leave(&game, -1);
    clear_board(game.board);
    if (game.ret == 2) return (2);
    if (game.ret == 1) return (1);
    return (0);
}
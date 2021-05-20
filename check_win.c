/*
** EPITECH PROJECT, 2021
** my sokoban
** File description:
** bootstrap
*/

#include "matchstick.h"

int know_if_win(game_t *game, int *p)
{
    if (check_win(game) >= 1) {
        if (*p == 0) {
            my_printf("I lost... snif... but I'll get you next time!!\n");
            *p = 1;
            game->ret = 1;
        }
        return (1);
    }
    return (0);
}
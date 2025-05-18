/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** handle_save1
*/

#include "game.h"
#include "init.h"

void handle_save1(game_handler_t *g_h)
{
    if (init_game(g_h, "save/save_1/"))
        return;
    g_h->screen_mode = S_GAME;
    return;
}

void handle_save2(game_handler_t *g_h)
{
    if (init_game(g_h, "save/save_3/"))
        return;
    g_h->screen_mode = S_GAME;
    return;
}

void handle_save3(game_handler_t *g_h)
{
    if (init_game(g_h, "save/save_2/"))
        return;
    g_h->screen_mode = S_GAME;
    return;
}

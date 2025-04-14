/*
** EPITECH PROJECT, 2025
** G-ING-210-REN-2-1-wolf3d-clovis.nedelec
** File description:
** init_game_handler
*/
#include "game.h"
#include "init.h"

int init_game_handler(game_handler_t *game_handler)
{
    game_handler->window = create_window();
    init_player(&game_handler->entities.player);
    return 0;
}
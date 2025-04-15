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
    init_map2d(&game_handler->map_2d);
    game_handler->general_clock.clock = sfClock_create();
    game_handler->map_2d.frame_rate_clock.clock = sfClock_create();
    if (game_handler->general_clock.clock == NULL
        || game_handler->window == NULL)
        return 84;
    return 0;
}

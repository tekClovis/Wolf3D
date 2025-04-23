/*
** EPITECH PROJECT, 2025
** G-ING-210-REN-2-1-wolf3d-clovis.nedelec
** File description:
** init_game_handler
*/
#include "game.h"
#include "init.h"
#include "ray_casting.h"

static
int init_binary_tree(ray_casting_t *binary_tree)
{
    binary_tree->node = malloc(sizeof(buffer_t) * WINDOW_SIZE_X);
    if (binary_tree->node == NULL)
        return 84;
    return 0;
}

int init_game_handler(game_handler_t *game_handler)
{
    sfTexture *wall = sfTexture_createFromFile("wall.bmp", NULL);

    game_handler->window = create_window();
    init_player(&game_handler->entities.player);
    init_map2d(&game_handler->map_2d);
    if (init_binary_tree(&game_handler->binary_tree))
        return 84;
    game_handler->window_mode = 0;
    game_handler->general_clock.clock = sfClock_create();
    game_handler->map_2d.frame_rate_clock.clock = sfClock_create();
    game_handler->wall = wall;
    if (game_handler->general_clock.clock == NULL
        || game_handler->window == NULL)
        return 84;
    return 0;
}

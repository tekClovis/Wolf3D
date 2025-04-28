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
int init_binary_tree(buffer_z_t **buffer_z)
{
    *buffer_z = malloc(sizeof(buffer_z_t) * WINDOW_SIZE_X);
    if (*buffer_z == NULL)
        return 84;
    return 0;
}

int init_controller(controller_t *controller)
{
    controller->control = 0;
    controller->time = init_clock();
}

int init_game_handler(game_handler_t *game_handler)
{
    sfTexture *wall = sfTexture_createFromFile("wall.bmp", NULL);

    game_handler->window = create_window();
    init_player(&game_handler->entities.player);
    init_wall(&game_handler->entities.object);
    init_controller(&game_handler->controller);
    if (init_binary_tree(&game_handler->buffer_z))
        return 84;
    game_handler->square = sfRectangleShape_create();
    game_handler->window_mode = 0;
    game_handler->general_clock.clock = sfClock_create();
    game_handler->wall = wall;
    if (game_handler->general_clock.clock == NULL
        || game_handler->window == NULL)
        return 84;
    return 0;
}

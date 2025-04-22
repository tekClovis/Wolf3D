/*
** EPITECH PROJECT, 2025
** G-ING-210-REN-2-1-wolf3d-clovis.nedelec
** File description:
** free_game
*/
#include "game.h"

static
void free_window(sfRenderWindow *window)
{
    sfRenderWindow_destroy(window);
}

static
void free_entities(entities_class_t *entity)
{
    sfSprite_destroy(entity->sprite);
    sfTexture_destroy(entity->texture);
}

static
void free_time_manage(time_management_t *time_manage)
{
    sfClock_destroy(time_manage->clock);
}

void free_game(game_handler_t *game_handler)
{
    free_window(game_handler->window);
    free_entities(&game_handler->entities.player);
}

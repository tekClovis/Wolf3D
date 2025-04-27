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
void free_entities(entities_class_t *entities)
{
    sfSprite_destroy(entities->sprite);
    sfTexture_destroy(entities->texture);
}

static
void free_player(player_t *player)
{
    free_entities(&player->property);
}

static
void free_entity(entities_handler_t *entities)
{
    free_player(&entities->player);
}

static
void free_time_manage(time_management_t *time_manage)
{
    sfClock_destroy(time_manage->clock);
}

void free_game(game_handler_t *game_handler)
{
    free_window(game_handler->window);
    free_entity(&game_handler->entities);
}

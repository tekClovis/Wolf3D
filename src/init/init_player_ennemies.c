/*
** EPITECH PROJECT, 2025
** G-ING-210-REN-2-1-wolf3d-clovis.nedelec
** File description:
** init_player_ennemies
*/
#include "game.h"

int init_player(player_t *player)
{
    player->angle = 0;
    player->guner_class = (guner_t){100, 0};
    player->property = (entities_class_t){(sfVector2f){0, 0}, NULL, NULL};
    return 0;
}

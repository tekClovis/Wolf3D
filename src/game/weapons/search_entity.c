/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** search_entity
*/
#include "game.h"

static
ennemies_t *verif_touch(list_t *ennemies, sfVector2f bullet)
{
    ennemies_t *act = NULL;

    for (node_t *cur = ennemies->head; cur; cur = cur->next){
        act = cur->data;
        if ((act->property->coord.x + act->property->hb_2d.x) < bullet.x &&
            (act->property->coord.x - act->property->hb_2d.x) > bullet.x &&
            (act->property->coord.y + act->property->hb_2d.y) > bullet.y &&
            (act->property->coord.y - act->property->hb_2d.y) > bullet.y)
            return act;
    }
    return NULL;
}

ennemies_t *search_entity(list_t *ennemies, player_t *player,
    game_handler_t *g_h)
{
    ennemies_t *touch = NULL;
    sfVector2f tmp = (sfVector2f){(sin(DEG_TO_RAD(-1 * player->
        property->angle))) * 1.1 + player->property->coord.x,
        cos(DEG_TO_RAD(-1 * player->property->angle))
        * 1.1 + player->property->coord.y};

    while (g_h->game->level.map[g_h->game->level.actual_level][(int)tmp.y][(int)tmp.x]
        != WALL_IRON){
        touch = verif_touch(ennemies, tmp);
        if (touch)
            break;
        tmp = (sfVector2f){(sin(DEG_TO_RAD(-1 * player->property->angle)))
            * 1.1 + tmp.x,
            cos(DEG_TO_RAD(-1 * player->property->angle))
            * 1.1 + tmp.y};
    }
    return touch;
}

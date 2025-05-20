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
        printf("hb_x: %f, hb_y: %f\n", act->property->hb_2d.x, act->property->hb_2d.y);
        printf("hb_x: %f, hb_y: %f\n", bullet.x, bullet.y);
        if ((act->property->coord.x + act->property->hb_2d.x) > bullet.x &&
            (act->property->coord.x - act->property->hb_2d.x) < bullet.x &&
            (act->property->coord.y + act->property->hb_2d.y) > bullet.y &&
            (act->property->coord.y - act->property->hb_2d.y) < bullet.y)
            return act;
    }
    return NULL;
}

ennemies_t *search_entity(list_t *ennemies, player_t *player,
    game_handler_t *g_h)
{
    ennemies_t *touch = NULL;
    sfVector2f tmp = (sfVector2f){(sin(DEG_TO_RAD(-1 * player->
        property->angle))) * 0.01 + player->property->coord.x,
        cos(DEG_TO_RAD(-1 * player->property->angle))
        * 0.01 + player->property->coord.y};

    while (g_h->game->level.map[g_h->game->level.actual_level]
        [(int)tmp.y][(int)tmp.x] != ID_WALL){
        //printf("y: %f, x: %f\n", tmp.y, tmp.x);
        touch = verif_touch(ennemies, tmp);
        if (touch){
            printf("\t id touch : %dx: %f, y: %f\\n", touch->property->id, tmp.x, tmp.y);
            break;
        }
        tmp = (sfVector2f){(sin(DEG_TO_RAD(-1 * player->property->angle)))
            * 0.1 + tmp.x,
            cos(DEG_TO_RAD(-1 * player->property->angle))
            * 0.1 + tmp.y};
    }
    return touch;
}

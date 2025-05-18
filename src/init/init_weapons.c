/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** init_weapons
*/

#include "game.h"

gun_t *init_knife()
{
    gun_t *knife = malloc(sizeof(gun_t));

    knife->img = set_img(T_3D_KNIFE, (sfVector2f){1300, 800});
    return knife;
}

gun_t **init_weapons(game_handler_t *g_h)
{
    gun_t **guns = malloc(sizeof(gun_t *) * NB_GUN);

    if (guns == NULL)
        return NULL;
    guns[W_ID_KNIFE] = init_knife();    
    return guns;
}

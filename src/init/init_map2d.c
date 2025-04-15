/*
** EPITECH PROJECT, 2025
** G-ING-210-REN-2-1-wolf3d-clovis.nedelec
** File description:
** init_map2d
*/

#include "game.h"

static
void init_player2d(class_map_t *map_2d)
{
    map_2d->map_player.coord = (sfVector2f){1920 / 2, 1080 / 2};
    map_2d->map_player.texture =
        sfTexture_createFromFile("player_2d.png", NULL);
    map_2d->map_player.sprite =
        sfSprite_create();
    sfSprite_setTexture(map_2d->map_player.sprite,
        map_2d->map_player.texture, sfTrue);
    sfSprite_setOrigin(map_2d->map_player.sprite,
        (sfVector2f){2.5, 3});
    sfSprite_setScale(map_2d->map_player.sprite,
        (sfVector2f){6, 6});
}

static
void init_wall2d(class_map_t *map_2d)
{
    map_2d->map_wall.texture = sfTexture_createFromFile("wall.png", NULL);
    map_2d->map_wall.sprite = sfSprite_create();
    sfSprite_setTexture(
        map_2d->map_wall.sprite, map_2d->map_wall.texture, sfTrue);
    sfSprite_setOrigin(map_2d->map_wall.sprite, (sfVector2f){0, 0});
    sfSprite_setScale(map_2d->map_wall.sprite, (sfVector2f){6, 6});
}

int init_map2d(class_map_t *map_2d)
{
    init_player2d(map_2d);
    init_wall2d(map_2d);
    return 0;
}

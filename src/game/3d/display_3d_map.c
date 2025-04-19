/*
** EPITECH PROJECT, 2025
** G-ING-210-REN-2-1-wolf3d-clovis.nedelec
** File description:
** display_3d_map
*/
#include "game.h"

void draw_ray_casting(game_handler_t *game_handler,
    sfRectangleShape *square, int i, int count)
{
    int ray = (i > 0) ? i : i * 1;
    float ray_angle = 0;
    float projected_height = 0;

    ray = (i > 0) ? i : i * 1;
    ray_angle = (-1 * game_handler->entities.player.angle)
        - (90 / 2) + ray;
    projected_height = 1000 / (get_coord_wall(game_handler, ray, 90)
        * cos(DEG_TO_RAD(ray)));
    sfRectangleShape_setSize(square,
        (sfVector2f){1980 / 90, projected_height});
    sfRectangleShape_setPosition(square,
        (sfVector2f){(1980 / 90) * count,
        1080 / 2 - (projected_height / 2)});
    sfRectangleShape_setFillColor(square, sfBlack);
    sfRenderWindow_drawRectangleShape(game_handler->window, square, NULL);
}

int display_3d_map(game_handler_t *game_handler)
{
    sfRectangleShape *square = sfRectangleShape_create();
    int ray = 0;
    int count = 0;

    sfRenderWindow_clear(game_handler->window, sfRed);
    for (float i = -45; i != 45; i++){
        draw_ray_casting(game_handler, square, i, count);
        count++;
    }
    sfRectangleShape_destroy(square);
    move_player(game_handler);
    rotate_player(game_handler);
    return 0;
}

/*
** EPITECH PROJECT, 2025
** G-ING-210-REN-2-1-wolf3d-clovis.nedelec
** File description:
** display_3d_map
*/
#include "game.h"

static
void display_floor(game_handler_t *game_handler, sfRectangleShape *square)
{
    sfColor my_color = {69, 200, 69, 255};

    sfRectangleShape_setSize(square, (sfVector2f){1980, 1082 / 2});
    sfRectangleShape_setPosition(square, (sfVector2f){0, 1080 / 2});
    sfRectangleShape_setFillColor(square, my_color);
    sfRenderWindow_drawRectangleShape(game_handler->window, square, NULL);
    sfRectangleShape_setFillColor(square, (sfColor){100, 100, 100, 255});
}

static
void draw_wall(game_handler_t *game_handler,
    sfRectangleShape *square, double i, double count)
{
    float ray = (i > 0) ? i : i * 1;
    float ray_angle = 0;
    float projected_height = 0;

    ray = (i > 0) ? i : i * 1;
    ray_angle = (-1 * game_handler->entities.player.angle)
        - (90 / 2) + ray;
    projected_height = 1000 / (get_coord_wall(game_handler, ray, 90)
    * cos(DEG_TO_RAD(ray)));
    sfRectangleShape_setSize(square,
        (sfVector2f){1980 / 770, projected_height});
    sfRectangleShape_setPosition(square,
        (sfVector2f){(1980 / 90) * count,
        1080 / 2 - (projected_height / 2)});
    sfRectangleShape_setTexture(square, game_handler->wall, sfTrue);
    sfRenderWindow_drawRectangleShape(game_handler->window, square, NULL);
}

void draw_ray_casting(game_handler_t *game_handler, sfRectangleShape *square)
{
    double count = 0;

    for (double i = -45; i < 45; i += 0.0625){
        draw_wall(game_handler, square, i, count);
        count += 0.0625;
    }
}

int display_3d_map(game_handler_t *game_handler)
{
    sfRectangleShape *square = sfRectangleShape_create();
    int ray = 0;
    sfColor color = {69, 69, 69, 0};

    sfRenderWindow_clear(game_handler->window, color);
    display_floor(game_handler, square);
    draw_ray_casting(game_handler, square);
    move_player(game_handler);
    rotate_player(game_handler);
    sfRectangleShape_destroy(square);
    return 0;
}

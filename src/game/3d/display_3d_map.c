/*
** EPITECH PROJECT, 2025
** G-ING-210-REN-2-1-wolf3d-clovis.nedelec
** File description:
** display_3d_map
*/
#include "game.h"

static
void display_floor(sfRenderWindow *window, sfRectangleShape *square)
{
    sfColor my_color = {69, 200, 69, 255};

    sfRectangleShape_setSize(square, (sfVector2f){1980, 1082 / 2});
    sfRectangleShape_setPosition(square, (sfVector2f){0, 1080 / 2});
    sfRectangleShape_setFillColor(square, my_color);
    sfRenderWindow_drawRectangleShape(window, square, NULL);
    sfRectangleShape_setFillColor(square, (sfColor){100, 100, 100, 255});
}

static void draw_wall(game_handler_t *gh, sfRectangleShape *square,
    double i, int iteration)
{
    double player_angle = DEG_TO_RAD(gh->entities.player.property.angle);
    double ray_angle_deg = player_angle + (double)i;
    double delta_rad = (ray_angle_deg - player_angle) * (M_PI / 180.0f);
    double ray_corr = get_coord_wall(&gh->entities.player.property,
    ray_angle_deg, 90.0f) * cos(delta_rad);
    double projection = (1 / ray_corr) * ((1980.0f * 0.5f) /
    tan((90.0f * 0.5f) * (M_PI / 180.0f)));

    sfRectangleShape_setSize(square, (sfVector2f){ RAY_SCREEN, projection });
    sfRectangleShape_setPosition(square, (sfVector2f){ RAY_SCREEN * iteration,
    (1080.0f * 0.5f) - (projection * 0.5f)});
    sfRectangleShape_setTexture(square, gh->wall, sfTrue);
    sfRenderWindow_drawRectangleShape(gh->window, square, NULL);
}

void draw_ray_casting(game_handler_t *game_handler, sfRectangleShape *square)
{
    int iteration = 0;

    for (double i = -45; i < 45; i += 0.0625){
        draw_wall(game_handler, square, i, iteration);
        iteration++;
    }
}

int display_3d_map(game_handler_t *game_handler)
{
    sfRectangleShape *square = sfRectangleShape_create();
    int ray = 0;
    sfColor color = {69, 69, 69, 0};

    sfRenderWindow_clear(game_handler->window, color);
    display_floor(game_handler->window, square);
    draw_ray_casting(game_handler, square);
    move_player(&game_handler->entities.player.property);
    rotate_player(&game_handler->entities.player.property);
    sfRectangleShape_destroy(square);
    return 0;
}

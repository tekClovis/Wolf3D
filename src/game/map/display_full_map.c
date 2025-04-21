/*
** EPITECH PROJECT, 2025
** G-ING-210-REN-2-1-wolf3d-clovis.nedelec
** File description:
** display_full_map
*/
#include "game.h"
#include "call_csfml.h"
#include "map.h"
#include <stdbool.h>
#include "entities.h"

/*
** convert the map
** to the map in memory
**
*/
sfVector2f get_coord(sfVector2f coord_window)
{
    coord_window.x -= (960 - ((60 * MAP_WIDTH) / 2));
    coord_window.y -= (520 - ((60 * MAP_HEIGHT) / 2));
    return (sfVector2f)
        {.x = (coord_window.x / 60),
        .y = (coord_window.y / 60)};
}

bool is_in_real_wall(sfVector2f coord)
{
    coord.x -= (960 - ((60 * MAP_WIDTH) / 2));
    coord.y -= (520 - ((60 * MAP_HEIGHT) / 2));
    if ((int)(coord.x) / 60 >= MAP_WIDTH || (int)(coord.y) / 60 >= MAP_HEIGHT)
        return true;
    if (is_wall((int)(coord.y) / 60, (int)(coord.x) / 60) == true)
        return true;
    return false;
}

int rotate_player(game_handler_t *game_handler)
{
    float time =
        game_handler->map_2d.frame_rate_clock.time_as_second;

    if (sfKeyboard_isKeyPressed(sfKeyRight)){
        game_handler->entities.player.angle += 5;
        if (game_handler->entities.player.angle >= 360)
            game_handler->entities.player.angle = 0;
        sfSprite_setRotation(game_handler->map_2d.map_player.sprite, 0);
        sfSprite_rotate(game_handler->map_2d.
            map_player.sprite, game_handler->entities.player.angle);
    }
    if (sfKeyboard_isKeyPressed(sfKeyLeft)){
        game_handler->entities.player.angle -= 5;
        if (game_handler->entities.player.angle <= 0)
            game_handler->entities.player.angle = 360;
        sfSprite_setRotation(game_handler->map_2d.map_player.sprite, 0);
        sfSprite_rotate(game_handler->map_2d.map_player.sprite,
            game_handler->entities.player.angle);
    }
    return 0;
}

static
void display_2dplayer(game_handler_t *game_handler)
{
    move_player(game_handler);
    rotate_player(game_handler);
    sfRenderWindow_drawSprite(game_handler->window,
        game_handler->map_2d.map_player.sprite, NULL);
    sfSprite_setPosition(game_handler->map_2d.map_player.sprite,
        game_handler->map_2d.map_player.coord);
}

static
void display_one_2dwall(game_handler_t *game_handler, int y)
{
    for (int x = 0; x < MAP_WIDTH; x++)
        if (is_wall(y, x) == true){
            sfSprite_setPosition(game_handler->map_2d.map_wall.sprite,
            (sfVector2f){((960 - ((60 * MAP_WIDTH) / 2))
            + (x * 60)), ((520 - ((60 * MAP_HEIGHT) / 2)) + (y * 60))});
            sfRenderWindow_drawSprite(game_handler->window,
                game_handler->map_2d.map_wall.sprite, NULL);
        }
}

static
void display_2dwalls(game_handler_t *game_handler)
{
    for (int y = 0; y < MAP_HEIGHT; y++)
        display_one_2dwall(game_handler, y);
}

static
sfVector2f dichotomie(game_handler_t *game_handler,
    float angle_option, int precision)
{
    sfVector2f tmp_coord;
    sfVector2f coord = game_handler->map_2d.map_player.coord;

    while (is_in_real_wall(coord) == false){
        tmp_coord = (sfVector2f){(sin(DEG_TO_RAD(-1 *
        (game_handler->entities.player.angle + angle_option))))
        * (precision), cos(DEG_TO_RAD(-1 *
        (game_handler->entities.player.angle + angle_option))) * (precision)};
        coord = (sfVector2f){coord.x + tmp_coord.x, coord.y + tmp_coord.y};
    }
    coord = (sfVector2f){coord.x - tmp_coord.x, coord.y - tmp_coord.y};
    return coord;
}

static
void display_ray_casting(game_handler_t *game_handler,
    float angle_option, int precision)
{
    sfVertexArray* line = sfVertexArray_create();
    sfVector2f coord = game_handler->map_2d.map_player.coord;
    sfVertex p1 = {coord, sfGreen, {0, 0}};
    sfVertex p2 = {coord, sfGreen, {0, 0}};

    for (int i = precision; i != 1; i = i / 2)
        coord = dichotomie(game_handler, angle_option, i);
    p2 = (sfVertex){coord, sfGreen, {0, 0}};
    sfVertexArray_setPrimitiveType(line, sfLines);
    sfVertexArray_append(line, p1);
    sfVertexArray_append(line, p2);
    sfRenderWindow_drawVertexArray(game_handler->window, line, NULL);
    sfVertexArray_destroy(line);
}

/*
** RAY CASTING
**
**
*/
float get_coord_wall(game_handler_t *game_handler, float angle, int precision)
{
    sfVector2f coord_player = game_handler->map_2d.map_player.coord;
    sfVector2f coord_wall = game_handler->map_2d.map_player.coord;
    sfVector2f player_in_map = {0, 0};
    sfVector2f wall_in_map = {0, 0};
    float dist = 0;

    for (int i = precision; i != 1; i = i / 2)
        coord_wall = dichotomie(game_handler, angle, i);
    player_in_map = get_coord(coord_player);
    wall_in_map = get_coord(coord_wall);
    dist = sqrt(((player_in_map.x - wall_in_map.x) *
    (player_in_map.x - wall_in_map.x)) +
    ((player_in_map.y - wall_in_map.y) *
    (player_in_map.y - wall_in_map.y)));
    return dist;
}

int display_full_map(game_handler_t *game_handler)
{
    sfRenderWindow_clear(game_handler->window, sfBlack);
    display_2dplayer(game_handler);
    display_2dwalls(game_handler);
    for (float i = -45; i < 45; i += 1){
        display_ray_casting(game_handler, i, 60);
    }
    return 0;
}

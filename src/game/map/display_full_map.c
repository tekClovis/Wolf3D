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
static bool is_in_real_wall(sfVector2f coord)
{
    coord.x -= (960 - ((60 * MAP_HEIGHT) / 2));
    coord.y -= (520 - ((60 * MAP_HEIGHT) / 2));
    printf("coord x: %d  || ", (int)(coord.x) / 60);
    printf("coord y: %d\n", (int)(coord.y) / 60);
    if ((int)(coord.x) / 60 >= MAP_HEIGHT || (int)(coord.y) / 60 >= MAP_WIDTH)
        return true;
    if (is_wall((int)(coord.x) / 60, (int)(coord.y) / 60) == true)
        return true;
    return false;
}

static
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
    for (int x = 0; x != MAP_WIDTH; x++)
        if (is_wall(x, y) == true){
            sfSprite_setPosition(game_handler->map_2d.map_wall.sprite,
                (sfVector2f){((960 - ((60 * MAP_HEIGHT) / 2))
                + (x * 60)), ((520 - ((60 * MAP_HEIGHT) / 2))
                + (y * 60))});
            sfRenderWindow_drawSprite(game_handler->window,
                game_handler->map_2d.map_wall.sprite, NULL);
        }
}

static
void display_2dwalls(game_handler_t *game_handler)
{
    for (int y = 0; y != MAP_HEIGHT; y++)
        display_one_2dwall(game_handler, y);
}

static
void display_ray_casting(game_handler_t *game_handler, float angle_option)
{
    sfVertexArray* line = sfVertexArray_create();
    sfVector2f coord = game_handler->map_2d.map_player.coord;
    sfVector2f tmp_coord;
    sfVertex p1 = {coord, sfGreen, {0, 0}};
    sfVertex p2 = {coord, sfGreen, {0, 0}};

    while (is_in_real_wall(coord) == false){
        tmp_coord = (sfVector2f){(sin(DEG_TO_RAD(-1 *
            (game_handler->entities.player.angle + angle_option))))
            * (15), cos(DEG_TO_RAD(-1 * (game_handler->entities.player.angle
            + angle_option))) * (15)};
        coord = (sfVector2f){coord.x + tmp_coord.x, coord.y + tmp_coord.y};
    }
    p2 = (sfVertex){coord, sfGreen, {0, 0}};
    sfVertexArray_setPrimitiveType(line, sfLines);
    sfVertexArray_append(line, p1);
    sfVertexArray_append(line, p2);
    sfRenderWindow_drawVertexArray(game_handler->window, line, NULL);
    sfVertexArray_destroy(line);
}

int display_full_map(game_handler_t *game_handler)
{
    sfRenderWindow_clear(game_handler->window, sfBlack);
    display_2dplayer(game_handler);
    display_2dwalls(game_handler);
    for (float i = -45; i < 45; i += 2)
        display_ray_casting(game_handler, i);
    return 0;
}

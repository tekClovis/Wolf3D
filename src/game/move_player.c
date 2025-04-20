/*
** EPITECH PROJECT, 2025
** G-ING-210-REN-2-1-wolf3d-clovis.nedelec
** File description:
** move_player
*/
#include "call_csfml.h"
#include "game.h"

static
void moove_up(game_handler_t *game_handler, sfVector2f *coord, float time)
{
    sfVector2f tmp = {0, 0};

    tmp = (sfVector2f){(sin(DEG_TO_RAD(-1 *
        game_handler->entities.player.angle)))
        * (MOVEMENT_SPEED_2D_MAP * time),
        cos(DEG_TO_RAD(-1 * game_handler->entities.player.angle))
        * (MOVEMENT_SPEED_2D_MAP * time)};
    if (is_in_real_wall(tmp) == true)
        return;
    *coord = tmp;
}

static
void moove_down(game_handler_t *game_handler, sfVector2f *coord, float time)
{
    sfVector2f tmp = {0, 0};

    tmp = (sfVector2f){-1 * (sin(DEG_TO_RAD(-1 *
        game_handler->entities.player.angle)))
        * (MOVEMENT_SPEED_2D_MAP * time), -1 *
        cos(DEG_TO_RAD(-1 * game_handler->entities.player.angle))
        * (MOVEMENT_SPEED_2D_MAP * time)};
    if (is_in_real_wall(tmp) == true)
        return;
    *coord = tmp;
}

static
void moove_right(game_handler_t *game_handler, sfVector2f *coord, float time)
{
    sfVector2f tmp = {0, 0};

    tmp = (sfVector2f){(sin((DEG_TO_RAD(-1 *
        game_handler->entities.player.angle)) - M_PI / 2)) *
        (MOVEMENT_SPEED_2D_MAP * time),
        cos((DEG_TO_RAD(-1 * game_handler->entities.player.angle))
        - M_PI / 2) * (MOVEMENT_SPEED_2D_MAP * time)};
    if (is_in_real_wall(tmp) == true)
        return;
    *coord = tmp;
}

static
void moove_left(game_handler_t *game_handler, sfVector2f *coord, float time)
{
    sfVector2f tmp = {0, 0};

    tmp = (sfVector2f){(sin((DEG_TO_RAD(-1 *
        game_handler->entities.player.angle))
        + M_PI / 2)) * (MOVEMENT_SPEED_2D_MAP * time),
        cos((DEG_TO_RAD(-1 * game_handler->entities.player.angle)) + M_PI / 2)
        * (MOVEMENT_SPEED_2D_MAP * time)};
    *coord = tmp;
}

int move_player(game_handler_t *game_handler)
{
    float time = sfTime_asSeconds(
        sfClock_restart(game_handler->map_2d.frame_rate_clock.clock));
    sfVector2f coord = {0, 0};

    game_handler->map_2d.
        frame_rate_clock.time_as_second = time;
    if (sfKeyboard_isKeyPressed(sfKeyZ))
        moove_up(game_handler, &coord, time);
    if (sfKeyboard_isKeyPressed(sfKeyS))
        moove_down(game_handler, &coord, time);
    if (sfKeyboard_isKeyPressed(sfKeyD))
        moove_right(game_handler, &coord, time);
    if (sfKeyboard_isKeyPressed(sfKeyQ))
        moove_left(game_handler, &coord, time);
    if (is_in_real_wall((sfVector2f){game_handler->map_2d.map_player.coord.x +
    coord.x, game_handler->map_2d.map_player.coord.y + coord.y}) == true)
        return 0;
    game_handler->map_2d.map_player.coord.x += coord.x;
    game_handler->map_2d.map_player.coord.y += coord.y;
    return 0;
}

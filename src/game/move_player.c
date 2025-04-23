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
        * (game_handler->entities.player.property.speed * time),
        cos(DEG_TO_RAD(-1 * game_handler->entities.player.angle))
        * (game_handler->entities.player.property.speed * time)};
    if (is_in_real_wall((sfVector2f){tmp.x + tmp.x, tmp.y + tmp.y}) == true)
        return;
    *coord = tmp;
}

static
void moove_down(game_handler_t *game_handler, sfVector2f *coord, float time)
{
    sfVector2f tmp = {0, 0};

    tmp = (sfVector2f){-1 * (sin(DEG_TO_RAD(-1 *
        game_handler->entities.player.angle)))
        * (game_handler->entities.player.property.speed * time), -1 *
        cos(DEG_TO_RAD(-1 * game_handler->entities.player.angle))
        * (game_handler->entities.player.property.speed * time)};
    if (is_in_real_wall((sfVector2f){tmp.x + tmp.x, tmp.y + tmp.y}) == true)
        return;
    *coord = tmp;
}

static
void moove_right(game_handler_t *game_handler, sfVector2f *coord, float time)
{
    sfVector2f tmp = {0, 0};

    tmp = (sfVector2f){(sin((DEG_TO_RAD(-1 *
        game_handler->entities.player.angle)) - M_PI / 2)) *
        (game_handler->entities.player.property.speed * time),
        cos((DEG_TO_RAD(-1 * game_handler->entities.player.angle))
        - M_PI / 2) * (game_handler->entities.player.property.speed * time)};
    if (is_in_real_wall((sfVector2f){tmp.x + tmp.x, tmp.y + tmp.y}) == true)
        return;
    *coord = tmp;
}

static
void moove_left(game_handler_t *game_handler, sfVector2f *coord, float time)
{
    sfVector2f tmp = {0, 0};

    tmp = (sfVector2f){(sin((DEG_TO_RAD(-1 *
        game_handler->entities.player.angle)) + M_PI / 2)) *
        (game_handler->entities.player.property.speed * time),
        cos((DEG_TO_RAD(-1 * game_handler->entities.player.angle))
        + M_PI / 2) * (game_handler->entities.player.property.speed * time)};
    if (is_in_real_wall((sfVector2f){tmp.x, tmp.y}) == true)
        return;
    *coord = tmp;
}

static
void move_came(game_handler_t *game_handler, sfVector2f *coord, float time)
{
    if (sfKeyboard_isKeyPressed(sfKeyZ))
        moove_up(game_handler, coord, time);
    if (sfKeyboard_isKeyPressed(sfKeyS))
        moove_down(game_handler, coord, time);
    if (sfKeyboard_isKeyPressed(sfKeyD))
        moove_right(game_handler, coord, time);
    if (sfKeyboard_isKeyPressed(sfKeyQ))
        moove_left(game_handler, coord, time);
}

void rotate_player(game_handler_t *game_handler)
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
}

void move_player(game_handler_t *game_handler)
{
    float time = sfTime_asSeconds(
        sfClock_restart(game_handler->map_2d.frame_rate_clock.clock));
    sfVector2f coord = {0, 0};

    game_handler->map_2d.
        frame_rate_clock.time_as_second = time;
   
    if (sfKeyboard_isKeyPressed(sfKeyLShift))
        game_handler->entities.player.property.speed = RUN;
    move_came(game_handler, &coord, time);
    if (is_in_real_wall((sfVector2f){game_handler->map_2d.map_player.coord.x +
        coord.x + coord.x / 3, game_handler->map_2d.map_player.coord.y +
        coord.y + coord.y / 3}) == true)
        return ;
    game_handler->map_2d.map_player.coord.x += coord.x;
    game_handler->map_2d.map_player.coord.y += coord.y;
    game_handler->entities.player.property.speed = WALK;
}

void manage_player(game_handler_t *game_handler)
{
    move_player(game_handler);
    rotate_player(game_handler);
}
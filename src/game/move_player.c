/*
** EPITECH PROJECT, 2025
** G-ING-210-REN-2-1-wolf3d-clovis.nedelec
** File description:
** move_player
*/
#include "call_csfml.h"
#include "game.h"

static
void moove_up(entities_class_t *entities, sfVector2f *coord, float time)
{
    sfVector2f tmp = {0, 0};

    tmp = (sfVector2f){(sin(DEG_TO_RAD(-1 *
        entities->angle)))
        * (entities->speed * time),
        cos(DEG_TO_RAD(-1 * entities->angle))
        * (entities->speed * time)};
    if (is_in_real_wall((sfVector2f){tmp.x + tmp.x, tmp.y + tmp.y}) == true)
        return;
    *coord = tmp;
}

static
void moove_down(entities_class_t *entities, sfVector2f *coord, float time)
{
    sfVector2f tmp = {0, 0};

    tmp = (sfVector2f){-1 * (sin(DEG_TO_RAD(-1 * entities->angle)))
        * (entities->speed * time), -1 *
        cos(DEG_TO_RAD(-1 * entities->angle))
        * (entities->speed * time)};
    if (is_in_real_wall((sfVector2f){tmp.x + tmp.x, tmp.y + tmp.y}) == true)
        return;
    *coord = tmp;
}

static
void moove_right(entities_class_t *entities, sfVector2f *coord, float time)
{
    sfVector2f tmp = {0, 0};

    tmp = (sfVector2f){(sin((DEG_TO_RAD(-1 * entities->angle)) - M_PI / 2)) *
        (entities->speed * time),
        cos((DEG_TO_RAD(-1 * entities->angle))
        - M_PI / 2) * (entities->speed * time)};
    if (is_in_real_wall((sfVector2f){tmp.x + tmp.x, tmp.y + tmp.y}) == true)
        return;
    *coord = tmp;
}

static
void moove_left(entities_class_t *entities, sfVector2f *coord, float time)
{
    sfVector2f tmp = {0, 0};

    tmp = (sfVector2f){(sin((DEG_TO_RAD(-1 * entities->angle)) + M_PI / 2)) *
        (entities->speed * time),
        cos((DEG_TO_RAD(-1 * entities->angle)) + M_PI / 2) *
        (entities->speed * time)};
    if (is_in_real_wall((sfVector2f){tmp.x, tmp.y}) == true)
        return;
    *coord = tmp;
}

static
void move_came(entities_class_t *player, sfVector2f *coord, float time)
{
    if (sfKeyboard_isKeyPressed(sfKeyZ))
        moove_up(player, coord, time);
    if (sfKeyboard_isKeyPressed(sfKeyS))
        moove_down(player, coord, time);
    if (sfKeyboard_isKeyPressed(sfKeyD))
        moove_right(player, coord, time);
    if (sfKeyboard_isKeyPressed(sfKeyQ))
        moove_left(player, coord, time);
    return;
}

void rotate_player(entities_class_t *entities)
{
    if (sfKeyboard_isKeyPressed(sfKeyRight)){
        entities->angle += 3;
        if (entities->angle >= 360)
            entities->angle = 0;
        sfSprite_setRotation(entities->sprite, 0);
        sfSprite_rotate(entities->sprite,
            entities->angle);
    }
    if (sfKeyboard_isKeyPressed(sfKeyLeft)){
        entities->angle -= 3;
        if (entities->angle <= 0)
            entities->angle = 360;
        sfSprite_setRotation(entities->sprite, 0);
        sfSprite_rotate(entities->sprite,
        entities->angle);
    }
}

void move_player(entities_class_t *entities)
{
    float time = sfTime_asSeconds(sfClock_restart(entities->clock.clock));
    sfVector2f coord = {0, 0};

    entities->clock.time_as_second = time;
    if (sfKeyboard_isKeyPressed(sfKeyLShift))
        entities->speed = RUN;
    move_came(entities, &coord, time);
    if (is_in_real_wall((sfVector2f){entities->coord.x + coord.x * 3,
        entities->coord.y + coord.y * 3}) == true)
        return;
    entities->coord.x += coord.x;
    entities->coord.y += coord.y;
    entities->speed = WALK;
}

void manage_player(game_handler_t *game_handler)
{
    move_player(&game_handler->entities.player.property);
    rotate_player(&game_handler->entities.player.property);
}

/*
Moove entity qui prend la struct entity et un define qui correspond
Au pointeur qui correspond au type d entité.

Move up down left right prend le type entities_class_t
*/

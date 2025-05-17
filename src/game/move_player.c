/*
** EPITECH PROJECT, 2025
** G-ING-210-REN-2-1-wolf3d-clovis.nedelec
** File description:
** move_player
*/
#include "call_csfml.h"
#include "game.h"
#include "controller.h"

static
void moove_up(entities_t *entities, sfVector2f *coord)
{
    sfVector2f tmp = {0, 0};
    float time = sfTime_asSeconds(sfClock_restart(entities->clock.clock));

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
void moove_down(entities_t *entities, sfVector2f *coord)
{
    sfVector2f tmp = {0, 0};
    float time = sfTime_asSeconds(sfClock_restart(entities->clock.clock));

    tmp = (sfVector2f){-1 * (sin(DEG_TO_RAD(-1 * entities->angle)))
        * (entities->speed * time), -1 *
        cos(DEG_TO_RAD(-1 * entities->angle))
        * (entities->speed * time)};
    if (is_in_real_wall((sfVector2f){tmp.x + tmp.x, tmp.y + tmp.y}) == true)
        return;
    *coord = tmp;
}

static
void moove_right(entities_t *entities, sfVector2f *coord)
{
    sfVector2f tmp = {0, 0};
    float time = sfTime_asSeconds(sfClock_restart(entities->clock.clock));

    tmp = (sfVector2f){(sin((DEG_TO_RAD(-1 * entities->angle)) - M_PI / 2)) *
        (entities->speed * time),
        cos((DEG_TO_RAD(-1 * entities->angle))
        - M_PI / 2) * (entities->speed * time)};
    if (is_in_real_wall((sfVector2f){tmp.x + tmp.x, tmp.y + tmp.y}) == true)
        return;
    *coord = tmp;
}

static
void moove_left(entities_t *entities, sfVector2f *coord)
{
    sfVector2f tmp = {0, 0};
    float time = sfTime_asSeconds(sfClock_restart(entities->clock.clock));

    tmp = (sfVector2f){(sin((DEG_TO_RAD(-1 * entities->angle)) + M_PI / 2)) *
        (entities->speed * time),
        cos((DEG_TO_RAD(-1 * entities->angle)) + M_PI / 2) *
        (entities->speed * time)};
    if (is_in_real_wall((sfVector2f){tmp.x, tmp.y}) == true)
        return;
    *coord = tmp;
}

static
bool move_came(entities_t *player, sfVector2f *coord)
{
    sfUint8 controller = get_left_stick();

    if (sfKeyboard_isKeyPressed(sfKeyZ) || controller & UP){
        moove_up(player, coord);
        return true;
    }
    if (sfKeyboard_isKeyPressed(sfKeyS) || controller & DOWN){
        moove_down(player, coord);
        return true;
    }
    if (sfKeyboard_isKeyPressed(sfKeyD) || controller & RIGHT){
        moove_right(player, coord);
        return true;
    }
    if (sfKeyboard_isKeyPressed(sfKeyQ) || controller & LEFT){
        moove_left(player, coord);
        return true;
    }
    return false;
}

/*
**Permet la gestion de rotation
**d' une entitée
*/
void rotate_player(entities_t *entities)
{
    sfUint8 controller = get_right_stick();

    if (sfKeyboard_isKeyPressed(sfKeyRight) || controller & RIGHT){
        entities->angle += 3;
        if (entities->angle >= 360)
            entities->angle = 0;
        sfSprite_setRotation(entities->img.sprite, 0);
        sfSprite_rotate(entities->img.sprite, entities->angle);
    }
    if (sfKeyboard_isKeyPressed(sfKeyLeft) || controller & LEFT){
        entities->angle -= 3;
        if (entities->angle <= 0)
            entities->angle = 360;
        sfSprite_setRotation(entities->img.sprite, 0);
        sfSprite_rotate(entities->img.sprite, entities->angle);
    }
}

/*
**Permet la gestion de mouvement
**du jouers et seulement le joueur
*/
void move_player(player_t *player)
{
    float time = sfTime_asSeconds(sfClock_restart(player->property->clock.clock));
    sfVector2f coord = {0, 0};

    player->property->clock.time_as_second = time;
    if (sfKeyboard_isKeyPressed(sfKeyLShift) || check_l3() == true)
        player->property->speed = RUN;
    if (move_came(player->property, &coord) &&
        need_refresh_clock(&player->clock_sound, 0.8f) == true)
        sfSound_play(player->step);
    if (is_in_real_wall((sfVector2f){player->property->coord.x + coord.x * 5,
        player->property->coord.y + coord.y * 5}) == true)
        return;
    player->property->coord.x += coord.x;
    player->property->coord.y += coord.y;
    player->property->speed = WALK;
}

void manage_player(game_handler_t *game_handler)
{
    move_player(game_handler->game->ent.player);
    rotate_player(game_handler->game->ent.player->property);
}

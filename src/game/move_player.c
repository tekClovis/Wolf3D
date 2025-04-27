/*
** EPITECH PROJECT, 2025
** G-ING-210-REN-2-1-wolf3d-clovis.nedelec
** File description:
** move_player
*/
#include "call_csfml.h"
#include "game.h"
#include "controller.h"

bool need_refresh_sound(time_management_t *sound_clock)
{
    sound_clock->time = sfClock_getElapsedTime(sound_clock->clock);
    sound_clock->time_as_second = sfTime_asSeconds(sound_clock->time);
    if (sound_clock->time_as_second > 0.8){
        sfClock_restart(sound_clock->clock);
        return true;
    }
    return false;
}

static
void moove_up(entities_class_t *entities, sfVector2f *coord, float time)
{
    sfVector2f tmp = {0, 0};

    if (need_refresh_sound(&entities->clock_sound) == true)
        sfSound_play(entities->step);
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

    if (need_refresh_sound(&entities->clock_sound) == true)
    sfSound_play(entities->step);
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

    if (need_refresh_sound(&entities->clock_sound) == true)
    sfSound_play(entities->step);
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

    if (need_refresh_sound(&entities->clock_sound) == true)
    sfSound_play(entities->step);
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
    sfUint8 controller = get_left_stick();

    if (sfKeyboard_isKeyPressed(sfKeyZ) || controller & UP)
        moove_up(player, coord, time);
    if (sfKeyboard_isKeyPressed(sfKeyS) || controller & DOWN)
        moove_down(player, coord, time);
    if (sfKeyboard_isKeyPressed(sfKeyD) || controller & RIGHT)
        moove_right(player, coord, time);
    if (sfKeyboard_isKeyPressed(sfKeyQ) || controller & LEFT)
        moove_left(player, coord, time);
    return;
}

/*
**Permet la gestion de rotation
**d' une entitée
*/
void rotate_player(entities_class_t *entities)
{
    sfUint8 controller = get_right_stick();

    if (sfKeyboard_isKeyPressed(sfKeyRight) || controller & RIGHT){
        entities->angle += 3;
        if (entities->angle >= 360)
            entities->angle = 0;
        sfSprite_setRotation(entities->sprite, 0);
        sfSprite_rotate(entities->sprite,
            entities->angle);
    }
    if (sfKeyboard_isKeyPressed(sfKeyLeft) || controller & LEFT){
        entities->angle -= 3;
        if (entities->angle <= 0)
            entities->angle = 360;
        sfSprite_setRotation(entities->sprite, 0);
        sfSprite_rotate(entities->sprite,
        entities->angle);
    }
}

/*
**Permet la gestion de mouvement
**du jouers et seulement le joueur
*/
void move_player(entities_class_t *entities)
{
    float time = sfTime_asSeconds(sfClock_restart(entities->clock.clock));
    sfVector2f coord = {0, 0};

    
    entities->clock.time_as_second = time;
    if (sfKeyboard_isKeyPressed(sfKeyLShift) || check_l3() == true)
        entities->speed = RUN;
    move_came(entities, &coord, time);
    if (is_in_real_wall((sfVector2f){entities->coord.x + coord.x * 5,
        entities->coord.y + coord.y * 5}) == true)
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

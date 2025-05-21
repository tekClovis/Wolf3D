/*
** EPITECH PROJECT, 2025
** G-ING-210-REN-2-1-wolf3d-clovis.nedelec
** File description:
** run_game
*/

#include "game.h"
#include "ray_casting.h"

/*
static
sfInt32 get_milisc_clock(time_management_t time_manage)
{
    sfclokc sfClock_getElapsedTime(entities->clock.clock);
    sfTime_asMilliseconds(entities->clock.clock);
}
*/
static
void new_moove_up(entities_t *entities)
{
    entities->coord.x += entities->dir.x / 10;
    entities->coord.y += entities->dir.y / 10;
}

static
void new_moove_down(entities_t *entities)
{
    entities->coord.x -= entities->dir.x / 10;
    entities->coord.y -= entities->dir.y / 10;
}

static
void new_moove_right(entities_t *entities)
{
    entities->coord.x += entities->dir.y / 10;
    entities->coord.y += -entities->dir.x / 10;
}

static
void new_moove_left(entities_t *entities)
{
    entities->coord.x -= entities->dir.y / 10;
    entities->coord.y -= -entities->dir.x / 10;
}

static
void new_moove_player(entities_t *player, sfEvent *event)
{
    if (sfKeyboard_isKeyPressed(sfKeyZ))
        new_moove_up(player);
    if (sfKeyboard_isKeyPressed(sfKeyS))
        new_moove_down(player);
    if (sfKeyboard_isKeyPressed(sfKeyQ))
        new_moove_left(player);
    if (sfKeyboard_isKeyPressed(sfKeyD))
        new_moove_right(player);
}

int run_game(game_handler_t *g_h)
{
    handle_player_shooting(g_h);
    new_rotate_player(g_h->game->ent->player->property, 0.03);
    new_moove_player(g_h->game->ent->player->property, g_h->event);
    execute_ray(g_h, g_h->game->ent->player->property);
    draw_screen(g_h);
    return 0;
}

/*
** EPITECH PROJECT, 2025
** G-ING-210-REN-2-1-wolf3d-clovis.nedelec
** File description:
** run_game
*/

#include "game.h"
#include "ray_casting.h"

static
void new_rotate_player(entities_t *player, float rot_speed)
{
    // Rotation vers la droite
    if (sfKeyboard_isKeyPressed(sfKeyRight)) {
        float old_dir_x = player->dir.x;
        player->dir.x = player->dir.x * cos(-rot_speed) - player->dir.y * sin(-rot_speed);
        player->dir.y = old_dir_x * sin(-rot_speed) + player->dir.y * cos(-rot_speed);

        float old_plane_x = player->plan.x;
        player->plan.x = player->plan.x * cos(-rot_speed) - player->plan.y * sin(-rot_speed);
        player->plan.y = old_plane_x * sin(-rot_speed) + player->plan.y * cos(-rot_speed);
    }

    // Rotation vers la gauche
    if (sfKeyboard_isKeyPressed(sfKeyLeft)) {
        float old_dir_x = player->dir.x;
        player->dir.x = player->dir.x * cos(rot_speed) - player->dir.y * sin(rot_speed);
        player->dir.y = old_dir_x * sin(rot_speed) + player->dir.y * cos(rot_speed);

        float old_plane_x = player->plan.x;
        player->plan.x = player->plan.x * cos(rot_speed) - player->plan.y * sin(rot_speed);
        player->plan.y = old_plane_x * sin(rot_speed) + player->plan.y * cos(rot_speed);
    }
}
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
    //if (event->type != sfEvtKeyPressed)
    //return;

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
    new_rotate_player(g_h->game->ent->player->property, 0.03);
    new_moove_player(g_h->game->ent->player->property, g_h->event);
    execute_ray(g_h, g_h->game->ent->player->property);
    draw_screen(&g_h->ray_cast, g_h->screen->win);
    return 0;
}
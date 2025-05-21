/*
** EPITECH PROJECT, 2025
** G-ING-210-REN-2-1-wolf3d-clovis.nedelec
** File description:
** run_game
*/

#include "game.h"
#include "ray_casting.h"
#include "entities.h"

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
void new_moove_player(player_t *player, hud_t *hud)
{
    if (sfKeyboard_isKeyPressed(sfKeyZ)){
        new_moove_up(player->property);
        player->inventory->gun[player->inventory->actual_gun]->img->pos.y
        += hud->to_move;
    }
    if (sfKeyboard_isKeyPressed(sfKeyS))
        new_moove_down(player->property);
    if (sfKeyboard_isKeyPressed(sfKeyQ))
        new_moove_left(player->property);
    if (sfKeyboard_isKeyPressed(sfKeyD))
        new_moove_right(player->property);
}

int run_game(game_handler_t *g_h)
{
    handle_ent_event(g_h, g_h->game->ent);
    handle_player_shooting(g_h);
    player_interaction(g_h->game->ent->player->property, NULL);
    new_moove_player(g_h->game->ent->player, g_h->game->hud);
    execute_ray(g_h, g_h->game->ent->player->property);
    draw_screen(g_h);
    return 0;
}

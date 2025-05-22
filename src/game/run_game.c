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

int run_game(game_handler_t *g_h)
{
    launch_ray(g_h, g_h->game->ent->player->property);
    if (!g_h->game->clock_game)
        g_h->game->clock_game = sfClock_create();
    handle_ent_event(g_h, g_h->game->ent);
    handle_player_shooting(g_h);
    player_interaction(g_h->game->ent->player->property, g_h);
    execute_ray(g_h, g_h->game->ent->player->property);
    draw_screen(g_h);
    return 0;
}

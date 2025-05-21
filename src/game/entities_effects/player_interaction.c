/*
** EPITECH PROJECT, 2025
** G-ING-210-REN-2-1-wolf3d-clovis.nedelec
** File description:
** player_interaction
*/

#include "game.h"


#define RST_CLOCK 0
#define LET_CLOCK 1
/*
return the time of clock
in millisecond
*/
sfInt32 get_milisc_clock(time_management_t *time_manage, int restart)
{
    time_manage->time = sfClock_getElapsedTime(time_manage->clock);
    time_manage->time_as_milli_sc = sfTime_asMilliseconds(time_manage->time);
    if (restart == RST_CLOCK)
        sfClock_restart(time_manage->clock);
    return time_manage->time_as_milli_sc;
}

void player_interaction(entities_t *player, sfEvent *event)
{
    sfInt32 time = get_milisc_clock(&player->clock, RST_CLOCK);

    new_rotate_player(player, 0.003, time, event);
}
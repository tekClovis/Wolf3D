/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** move_ennemies
*/

#include "game.h"

static
void anim_move_brut(ennemies_t *ennemies, sfInt32 tim_mili,
    game_handler_t *g_h)
{
    if (sfClock_getElapsedTime(ennemies->clock_move.clock).microseconds
        / 1000.0 > 300.0){
        ennemies->property->img->rect.top = 0;
        if (ennemies->property->img->rect.left >
            ennemies->property->img->rect.width * 3)
            ennemies->property->img->rect.left = 0;
        if (ennemies->anim == 1)
            ennemies->property->img->rect.left +=
                ennemies->property->img->rect.width;
        ennemies->anim = 1;
        new_moove_up(ennemies->property, tim_mili * 1.5, g_h->game->level.map
            [g_h->game->level.actual_level]);
        sfClock_restart(ennemies->clock_move.clock);
    }
}

void move_ennemies(ennemies_t *ennemies, game_handler_t *g_h)
{
    sfInt32 tim_mili = get_milisc_clock(&ennemies->property->clock,
        RST_CLOCK);

    if (ennemies->property->id == ID_BRUT){
        anim_move_brut(ennemies, tim_mili, g_h);
    }
}

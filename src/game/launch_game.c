/*
** EPITECH PROJECT, 2025
** bootstrap
** File description:
** launch_game
*/
#include "game.h"
#include <stdbool.h>
#include "controller.h"

void applied_event(sfRenderWindow *window, sfEvent event)
{
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(window);
}

sfUint8 get_controller_button(void)
{
    sfUint8 controller = 0;

    if (check_cross() == true)
        controller |= DOWN;
    if (check_triangle() == true)
        controller |= UP;
    if (check_square() == true)
        controller |= LEFT;
    if (check_circle() == true)
        controller |= RIGHT;
    return controller;
}

/*
** Récupère l evenement du jeu actuel
** et set la clock de fram rate
*/

bool need_refresh(game_handler_t *game_handler)
{
    game_handler->general_clock.time
        = sfClock_getElapsedTime(game_handler->general_clock.clock);
    game_handler->general_clock.time_as_micro_second
        = sfTime_asMicroseconds(game_handler->general_clock.time);
    if (game_handler->general_clock.time_as_micro_second > 16.666){
        sfClock_restart(game_handler->general_clock.clock);
        return true;
    }
    return false;
}

int launch_game(game_handler_t *game_handler)
{
    sfRenderWindow_setFramerateLimit(game_handler->screen->win, 60);
    while (sfRenderWindow_isOpen(game_handler->screen->win)){
        sfRenderWindow_clear(game_handler->screen->win, sfBlack);
        if (need_refresh(game_handler) == false)
            continue;
        //handle_ent_event(game_handler);
        choose_window_mode(game_handler);
        sfRenderWindow_display(game_handler->screen->win);
    }
    return 0;
}

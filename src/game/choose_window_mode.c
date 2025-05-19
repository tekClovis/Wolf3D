/*
** EPITECH PROJECT, 2025
** G-ING-210-REN-2-1-wolf3d-clovis.nedelec
** File description:
** choose_window_mode
*/
#include "game.h"
#include "menu.h"

/*
**Start game vas contenir
**tout pour determiner quoi choisir
**pour chargé une sauvegarde ou initialisé une map
**
*/

const game_mode_t tab_func[] = {
    {&display_menu},
    {NULL},
    {&run_game},
    //{&display_3d_map},
    {NULL}
};

int choose_window_mode(game_handler_t *game_handler)
{
    return tab_func[game_handler->screen_mode].funct(game_handler);
}

void check_back_to_menu(game_handler_t *handler)
{
    if (sfKeyboard_isKeyPressed(sfKeyEscape) || check_square() == true)
        handler->screen->win = 0;
}

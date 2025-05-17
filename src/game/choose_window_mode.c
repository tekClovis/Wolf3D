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
    //{&display_full_map},
    //{&display_3d_map},
    {NULL}
};

static int change_window(game_handler_t *game_handler)
{
    if (sfKeyboard_isKeyPressed(sfKeyNumpad1)
    || game_handler->controller.control & UP)
        game_handler->screen_mode = 1;
    if (sfKeyboard_isKeyPressed(sfKeyNumpad2)
    || game_handler->controller.control & UP)
        game_handler->screen_mode = 2;
    return 0;
}

int choose_window_mode(game_handler_t *game_handler)
{
    change_window(game_handler);
    return tab_func[game_handler->screen_mode].funct(game_handler);
}

void check_back_to_menu(game_handler_t *handler)
{
    if (sfKeyboard_isKeyPressed(sfKeyEscape) || check_square() == true)
        handler->screen->win = 0;
}

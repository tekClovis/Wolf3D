/*
** EPITECH PROJECT, 2025
** G-ING-210-REN-2-1-wolf3d-clovis.nedelec
** File description:
** choose_window_mode
*/
#include "game.h"

/*
**Start game vas contenir
**tout pour determiner quoi choisir
**pour chargé une sauvegarde ou initialisé une map
**
*/

const game_mode_t tab_func[] = {
    {&display_full_map},
    {&display_3d_map},
    {NULL}
};

//display the map in full screen
//{&start_game}
//{&mode_menu},//active the menu mode
//{&display_game}//3d_game with mini maps

static
int change_window(game_handler_t *game_handler)
{
    if (sfKeyboard_isKeyPressed(sfKeyNumpad1))
        game_handler->window_mode = 0;
    if (sfKeyboard_isKeyPressed(sfKeyNumpad2))
        game_handler->window_mode = 1;
    return 0;
}

int choose_window_mode(game_handler_t *game_handler)
{
    change_window(game_handler);
    return tab_func[game_handler->window_mode].funct(game_handler);
}

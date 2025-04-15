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
    {NULL}
};

//display the map in full screen
//{&start_game}
//{&mode_menu},//active the menu mode
//{&display_game}//3d_game with mini maps


int choose_window_mode(game_handler_t *game_handler)
{
    return tab_func[0].funct(game_handler);
}

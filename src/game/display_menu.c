/*
** EPITECH PROJECT, 2025
** Wolf3D
** File description:
** display_menu
*/

#include "game.h"
#include "call_csfml.h"

int display_menu(game_handler_t *handler)
{
    sfRenderWindow_clear(handler->window, sfBlack);
    sfRenderWindow_drawSprite(handler->window, handler->menu->sprite, NULL);
    return 0;
}

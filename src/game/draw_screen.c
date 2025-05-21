/*
** EPITECH PROJECT, 2025
** G-ING-210-REN-2-1-wolf3d-clovis.nedelec
** File description:
** draw_screen
*/

#include "game.h"
#include "ray_casting.h"

/*CALL all the function to draw*/
void draw_screen(game_handler_t *game)
{
    draw_wall(&game->ray_cast, game->screen->win);
    draw_sprite(game, game->screen->win);
    draw_hud(game->game->hud, game);
}
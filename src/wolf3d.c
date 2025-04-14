/*
** EPITECH PROJECT, 2025
** bootstrap
** File description:
** wolf3d
*/
#include "call_csfml.h"
#include "init.h"
#include "map.h"
#include <time.h>
#include "game.h"

int wolf3d(void)
{
    game_handler_t game_handler;
    int error = 0;

    error = init_game_handler(&game_handler);
    if (error == 84)
        return 84;
    launch_game();
    return 0;
}
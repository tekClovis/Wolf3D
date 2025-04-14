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

int wolf3d(void)
{
    sfRenderWindow *window = create_window();
    /*init some struct*/

    launch_game(window);
    return 0;
}
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

    while (1)
    {
        sleep(1);
        if (is_wall(0, 0) == 0)
            printf("Je suis un wall\n");
        else
            printf("Je ne suis pas un wall\n");
    }
    
    return 0;
}
/*
** EPITECH PROJECT, 2025
** bootstrap
** File description:
** is_wall
*/
#include "map.h"

/*
** return 0 
** si c' est un wall
** sinon 1
*/

int is_wall(int x, int y)
{
    if (map[x][y] == 1)
        return 0;
    return 1;
}
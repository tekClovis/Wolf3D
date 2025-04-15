/*
** EPITECH PROJECT, 2025
** bootstrap
** File description:
** is_wall
*/
#include "map.h"
#include <stdbool.h>
/*
** return 0
** si c' est un wall
** sinon 1
*/

bool is_wall(int x, int y)
{
    if (map[x][y] == 1)
        return true;
    return false;
}

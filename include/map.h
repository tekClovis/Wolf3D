/*
** EPITECH PROJECT, 2025
** minishell
** File description:
** my
*/


#ifndef MAP_H
    #define MAP_H
    # define TILE_SIZE 60
    # define MAP_WIDTH 8
    # define MAP_HEIGHT 8
    #include <stdbool.h>

/*
** Variable externe
** qui sera changé
** par des fichier de
** config
*/
extern int const map[MAP_HEIGHT][MAP_WIDTH];

bool is_wall(int x, int y);

#endif //MAP_H

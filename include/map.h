/*
** EPITECH PROJECT, 2025
** minishell
** File description:
** my
*/


#ifndef MAP_H
    #define MAP_H
    # define TILE_SIZE 64
    # define MAP_WIDTH 8
    # define MAP_HEIGHT 8

    extern int map[MAP_HEIGHT][MAP_WIDTH];

    int is_wall(int x, int y);
    
#endif //MAP_H
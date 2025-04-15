/*
** EPITECH PROJECT, 2025
** minishell
** File description:
** my
*/


#ifndef INIT_H
    #define INIT_H

    #include "call_csfml.h"
    #include "game.h"

sfRenderWindow *create_window(void);
int init_map2d(class_map_t *map_2d);
int init_game_handler(game_handler_t *game_handler);
void init_player(player_t *player);

#endif //INIT_H

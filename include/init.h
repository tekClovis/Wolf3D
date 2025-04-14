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
int init_game_handler(game_handler_t *game_handler);
void init_player(player_t* player ); // Initializes the player 's position and angle
//int is_wall ( int x , int y ) ; // Returns 1 if the position corresponds to a wall
//void draw_floor_and_ceiling ( sfRenderWindow * window ) ; // Draws the floor and ceiling of the

#endif //INIT_H

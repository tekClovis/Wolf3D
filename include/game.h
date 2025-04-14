/*
** EPITECH PROJECT, 2025
** minishell
** File description:
** my
*/


#ifndef GAME_H
    #define GAME_H
    #include "entities.h"
    #include "call_csfml.h"
/*
** Entitie handler
** contient toute les 
** entité
*/
typedef struct entities_handler_s{
    player_t player;
    object_handler_t object;
    ennemies_t ennemies;
}entities_handler_t;

typedef struct game_handler_s
{
    entities_handler_t entities;
    sfRenderWindow *window;
}game_handler_t;

int launch_game(game_handler_t *game_handler);

#endif //GAME_H
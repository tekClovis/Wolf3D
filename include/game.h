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
}entities_handler_t;

typedef struct game_handler_s
{

}game_handler_t;
#endif //GAME_H
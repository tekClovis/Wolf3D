/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** handle_ent_event
*/
#include "game.h"
#include "entities.h"


void handle_ent_env(game_handler_t *game_handler)
{
    node_t *actual = game_handler->entities.ennemies->head;
    player_t *player = &game_handler->entities.player;

    for (; actual; actual = actual->next){
        detect_player(actual->data, &game_handler->entities.player);
        if (((ennemies_t *)actual->data)->can_shoot){
            ((ennemies_t *)actual->data)->gun_shot(player, actual->data);
            continue;
        }
        
    }
}

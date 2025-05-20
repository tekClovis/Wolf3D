/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** free_game
*/

#include "game.h"

static
void save_game(game_t *game, game_handler_t *g_h)
{
    save_to_file(g_h, "score_nb.bin", &game->score.score,
        sizeof(game->score.score));
    save_to_file(g_h, "score_time.bin", &game->score.score,
        sizeof(game->score.score));
    save_to_file(g_h, "actual_level.bin", &game->level.actual_level,
        sizeof(game->level.actual_level));
    if (game->ent->player->property->life > 0)
        save_to_file(g_h, "life.bin", &game->ent->player->property->life,
        sizeof(game->ent->player->property->life));
    save_to_file(g_h, "nb_gun.bin", &game->ent->player->inventory->nb_of_gun,
        sizeof(game->ent->player->inventory->nb_of_gun));
    for (int i = W_ID_GUN; i < NB_GUN; i++)
        save_to_file(g_h, g_h->game->ent->player->inventory->gun[i]->save_file
            , &g_h->game->ent->player->inventory->gun[i]->ammo,
            sizeof(g_h->game->ent->player->inventory->gun[i]->ammo));
}

void free_game(game_handler_t *g_h)
{
    save_game(g_h->game, g_h);
}

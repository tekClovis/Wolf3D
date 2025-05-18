/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** init_game
*/

#include "game.h"
#include "init.h"
#include "call_csfml.h"
#include "string.h"

bool init_game(game_handler_t *g_h, char *save_dir)
{
    g_h->game = malloc(sizeof(game_t));
    if (g_h->game == NULL)
        return false;
    g_h->game->ent = malloc(sizeof(entities_handler_t));
    g_h->game->uid = malloc(sizeof(p_uid_t));
    g_h->game->actual_save = strdup(save_dir);
    if (g_h->game->ent == NULL || g_h->game->uid == NULL)
        return false;
    g_h->game->game_music = init_music("game_music.ogg", g_h);
    if (!load_map(g_h->game->game_music, strcat(save_dir, "level.bin")))
        return false;
    if (!init_player(g_h, save_dir))
        return false;
}

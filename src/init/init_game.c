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

static
score_t init_score(game_handler_t *g_h)
{
    score_t score;

    if (!load_from_file(g_h, "score_nb.bin", &score.score,
        sizeof(score.score)))
        score.score = 0;
    if (!load_from_file(g_h, "score_time.bin", &score.score,
        sizeof(score.score)))
        score.score_mili_s = 0;
    score.time_to_end = init_clock();
    return score;
}

bool init_game(game_handler_t *g_h, char *save_dir)
{
    g_h->game = malloc(sizeof(game_t));
    if (g_h->game == NULL)
        return false;
    g_h->game->ent = malloc(sizeof(entities_handler_t));
    g_h->game->uid = malloc(sizeof(p_uid_t));
    g_h->game->actual_save = strdup(save_dir);
    g_h->game->score = init_score(g_h);
    if (g_h->game->ent == NULL || g_h->game->uid == NULL)
        return false;
    g_h->game->game_music = init_music("sound/game_music.ogg", g_h);
    if (!load_map(g_h))
        return false;
    if (!init_player(g_h))
        return false;
    if (!parsing_map(g_h))
        return false;
    return true;
}

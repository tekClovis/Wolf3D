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

static
img_t **init_weapons_two_d(game_handler_t *g_h)
{
    img_t **wp_two_d = malloc(sizeof(img_t *) * NB_GUN);

    if (wp_two_d == NULL)
        return NULL;
    wp_two_d[0] = set_img(T_2D_KNIFE, (sfIntRect){0, 0, 0, 0}
        , (sfVector2f){1800, 400}, g_h);
    wp_two_d[1] = set_img(T_2D_GUN, (sfIntRect){0, 0, 0, 0}
        , (sfVector2f){1800, 400}, g_h);
    wp_two_d[2] = set_img(T_2D_SHOTGUN, (sfIntRect){0, 0, 0, 0}
        , (sfVector2f){1800, 400}, g_h);
    wp_two_d[3] = set_img(T_2D_MINIGUN, (sfIntRect){0, 0, 0, 0}
        , (sfVector2f){1800, 400}, g_h);
    if (wp_two_d[0] || wp_two_d[1] || wp_two_d[2] || wp_two_d[3])
        return free(wp_two_d) ,NULL;
    return wp_two_d;
}

static
bool init_hud(game_handler_t *g_h)
{
    g_h->game->hud = malloc(sizeof(hud_t));
    if (g_h->game->hud == NULL)
        return false;
    g_h->game->hud->bg_player_info = set_img(T_HUD, (sfIntRect){0, 0, 0, 0},
        (sfVector2f){375, 800}, g_h);
    g_h->game->hud->magazine = set_txt(80, sfColor_fromRGB(105,105,105), 
        (sfVector2f){495, 820}, "6");
    g_h->game->hud->life = set_txt(80, sfColor_fromRGB(105,105,105), 
            (sfVector2f){715, 820}, "0");
    g_h->game->hud->time = set_txt(80, sfColor_fromRGB(105,105,105), 
        (sfVector2f){150, 10}, "SCORE : ");
    g_h->game->hud->score = set_txt(80, sfColor_fromRGB(105,105,105), 
        (sfVector2f){400, 5}, "0");
    g_h->game->hud->weapon_two_d = init_weapons_two_d(g_h);
    g_h->game->hud->actual_weapon = set_img(T_2D_GUN, (sfIntRect){0, 0, 0, 0},
        (sfVector2f){1325, 780}, g_h);
    return true;
}

static
entities_handler_t *init_handler(void)
{
    entities_handler_t *ent = malloc(sizeof(entities_handler_t));

    if (ent == NULL)
        return NULL;
    ent->ennemies = list_create();
    if (ent->ennemies == NULL)
        return free(ent), NULL;
    ent->entities = list_create();
    if (ent->entities == NULL)
        return free(ent), NULL;
    return ent;
}

bool init_game(game_handler_t *g_h, char *save_dir)
{
    g_h->game = malloc(sizeof(game_t));
    if (g_h->game == NULL)
        return false;
    g_h->game->ent = init_handler();
    g_h->game->actual_save = strdup(save_dir);
    g_h->game->score = init_score(g_h);
    if (g_h->game->ent == NULL)
        return false;
    g_h->game->game_music = init_music("sound/game_music.ogg", g_h);
    if (!load_map(g_h))
        return false;
    if (!init_player(g_h))
        return false;
    if (!parsing_map(g_h))
        return false;
    if (!init_hud(g_h) || !init_ray_buffer(&g_h->ray_cast))
        return false;
    return true;
}

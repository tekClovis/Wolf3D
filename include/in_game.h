/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** in_game
*/

#ifndef INCLUDED_IN_GAME_H
    #define INCLUDED_IN_GAME_H
    #include "entities.h"
    #include "time.h"
    #include "level.h"

typedef struct score_s {
    int score;
    time_management_t time_to_end;
    sfInt32 score_mili_s;
} score_t;

//weapon 2 d fois 4 img_t
typedef struct hud_s {
    img_t *bg_player_info;
    img_t **weapon_two_d;
    sfText *time;
    sfText *magazine;
    sfText *ammo;
    sfText *score;
    img_t *actual_weapon;
} hud_t;

typedef struct game_s {
    entities_handler_t *ent;
    level_t level;
    hud_t *hud;
    score_t score;
    sfMusic *game_music;
    char *actual_save;
} game_t;

void handle_game_event(game_handler_t *g_h);

#endif

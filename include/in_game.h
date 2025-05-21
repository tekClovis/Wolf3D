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

typedef struct anim_s {
    void(*func)(game_handler_t *, gun_t *);
} anim_t;   

/*Draw sprite permet de mettre en relation le z buffer
contenu dans la strut de ray casting et de calculer
comment draw chaque sprite.
------
sprite coord correspond a la position relatif de l
entité par rapport au repert joueur
------
inv_mat calcul de la matrice inverse pour calculé 
transform X et Y
------
Transform X correspond a la postion lateral 
en rapport avec la camera
Transform Y permet de déterminer si le sprite et 
derriere ou devant le sprite
-----
sprite_screen_x calcul ou on draw le sprite
0 < sprite_screen_x < 1920
*/
typedef struct draw_sprite_s {
    sfVector2f sprite_coord;
    double inv_mat;
    sfVector2f transform;
    int sprite_screen_x;
} draw_sprite_t;


//weapon 2 d fois 4 img_t
typedef struct hud_s {
    img_t *bg_player_info;
    img_t **weapon_two_d;
    sfText *time;
    sfText *magazine;
    sfText *ammo;
    sfText *score;
    sfText *life;
    img_t *actual_weapon;
    sfClock *animation;
    bool anim;
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

/*
** EPITECH PROJECT, 2025
** minishell
** File description:
** my
*/

#ifndef ENTITIES_H
    #define ENTITIES_H
    #include "stdbool.h"
    #include "call_csfml.h"
    #include "time.h"
    #include "my.h"
    #define SS 2
    #define MUTANT 3
    #define BRUT 4
    #define PLAYER_MOVE 0
    #define ENNEMIE_MOVE 1
    #define OBJECT_MOVE 2

typedef struct entities_class_s {
    sfVector2f coord;
    sfSprite *sprite;
    sfTexture *texture;
    time_management_t clock;
    sfVector2f hb_2d;
    int id;
    int speed;
    float angle;
    int life;
    sfSound *step;
    sfSoundBuffer *sound_buff;
    time_management_t clock_sound;
}entities_class_t;

typedef struct player_s {
    entities_class_t property;
    int (*gun_shot)(player_t *, ennemies_t *);
    float angle;
}player_t;

typedef struct ennemies_s {
    entities_class_t property;
    bool can_shoot;
    time_management_t hit_clock;
    int (*gun_shot)(player_t *, ennemies_t *);
}ennemies_t;

typedef struct object_s {
    entities_class_t property;
    size_t size;
    size_t alloc;
}object_handler_t;

typedef struct {
    sfVector2f angle_interval;
    int sprite_coef;
} angle_sprite_t;

void handle_ent_env(game_handler_t *game_handler);
#endif //ENTITIES_H

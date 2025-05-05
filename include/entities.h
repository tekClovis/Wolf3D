/*
** EPITECH PROJECT, 2025
** minishell
** File description:
** my
*/

#ifndef ENTITIES_H
    #define ENTITIES_H
    #include "stdbool.h"
    #include "stdbool.h"
    #include "call_csfml.h"
    #include "game.h"
    #include "time.h"
    #include "my.h"
    #define PLAYER 2
    #define SS 3
    #define MUTANT 4
    #define BRUT 5

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
    sfVector2f collision;
}entities_class_t;

typedef struct ennemies_s ennemies_t;
typedef struct player_s player_t;

struct ennemies_s {
    entities_class_t property;
    bool can_shoot;
    time_management_t hit_clock;
    int (*gun_shot)(list_t *, ennemies_t *, player_t *);
};

struct player_s {
    entities_class_t property;
    int (*gun_shot)(list_t *,  ennemies_t *, player_t *);
    float angle;
};

typedef struct object_s {
    entities_class_t property;
    size_t size;
    size_t alloc;
}object_handler_t;

typedef struct {
    sfVector2f angle_interval;
    int sprite_coef;
} angle_sprite_t;

#endif //ENTITIES_H

/*
** EPITECH PROJECT, 2025
** minishell
** File description:
** my
*/

#ifndef ENTITIES_H
    #define ENTITIES_H
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
    sfVector2f collision;
}entities_class_t;

typedef struct{
    ammo;
    magazine;
}gun_stat_t;

typedef struct{
    int (*gun_shot)(list_t *, entities_class_t);
    int nb_of_gun;
    int actual_gun;
    gun_stat_t stat[3];
} gun_t;

typedef struct player_s {
    entities_class_t property;
    gun_t gun;
    float angle;
}player_t;

typedef struct ennemies_s {
    entities_class_t property;
    int (*gun_shot)(list_t *, entities_class_t);
}ennemies_t;

typedef struct object_s {
    entities_class_t property;
    size_t size;
    size_t alloc;
}object_handler_t;


#endif //ENTITIES_H

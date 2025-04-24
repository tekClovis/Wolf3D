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
}entities_class_t;

typedef struct player_s {
    entities_class_t property;
    int (*gun_shot)(player_t *, ennemies_t *);
    float angle;
}player_t;

typedef struct ennemies_s {
    entities_class_t property;
    bool can_shoot;
    int (*gun_shot)(player_t *, ennemies_t *);
}ennemies_t;

typedef struct object_s {
    entities_class_t property;
    size_t size;
    size_t alloc;
}object_handler_t;

void handle_ent_env(game_handler_t *game_handler);
#endif //ENTITIES_H

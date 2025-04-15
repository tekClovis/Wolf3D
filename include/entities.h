/*
** EPITECH PROJECT, 2025
** minishell
** File description:
** my
*/


#ifndef ENTITIES_H
    #define ENTITIES_H

    #include "call_csfml.h"

typedef struct entities_class_s {
    sfVector2f coord;
    sfSprite *sprite;
    sfTexture *texture;
}entities_class_t;

typedef struct guner_s {
    int life;
    int weapon;
}guner_t;

typedef struct player_s {
    entities_class_t property;
    guner_t guner_class;
    float angle;
}player_t;

typedef struct ennemy_s {
    entities_class_t property;
    guner_t guner_class;
}ennemy_t;

typedef struct object_s {
    entities_class_t property;
    size_t size;
    size_t alloc;
}object_handler_t;

/*
** Mettre une énume
** pour les weapons
**
*/


typedef struct ennemies_s {
    sfVector2f coord;
    int life;
}ennemies_t;

#endif //ENTITIES_H

/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** weapons
*/

#ifndef INCLUDED_WEAPONS_H
    #define INCLUDED_WEAPONS_H
    #include "stdbool.h"
    #include "call_csfml.h"
    #include "entities.h"
    #include "time.h"
    #include "my.h"
    #define KNIFE 1
    #define GUN 2
    #define ASSAULT 3
    #define MINIGUN 4

int minigun_shoot(list_t *entities, entities_class_t *shooter);
int gun_shoot(list_t *entities, entities_class_t *shooter);
int assault_shoot(list_t *entities, entities_class_t *shooter);
int knife_shoot(list_t *entities, entities_class_t *shooter);
#endif

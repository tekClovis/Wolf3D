/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** weapons
*/
#include "call_csfml.h"
#include "game.h"
#include "my.h"


int pistol_shoot(list_t *entities, entities_class_t *shooter)
{
    return 0;
}

int shotgun_shoot(list_t *entities, entities_class_t *shooter)
{
    return 0;
}

int minigun_shoot(list_t *entities, entities_class_t *shooter)
{
    if (shooter->id == PLAYER)
        handle_player_shoot(shooter);
    return 0;
}

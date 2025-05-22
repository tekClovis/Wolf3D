/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** move_ent
*/
#include "game.h"

void new_moove_up(entities_t *entities, sfInt32 tim_mili)
{
    entities->coord.x += (entities->dir.x / 500.0) * tim_mili;
    entities->coord.y += (entities->dir.y / 500.0) * tim_mili;
}

void new_moove_down(entities_t *entities, sfInt32 tim_mili)
{
    entities->coord.x -= (entities->dir.x / 500.0) * tim_mili;
    entities->coord.y -= (entities->dir.y / 500.0) * tim_mili;
}

void new_moove_right(entities_t *entities, sfInt32 tim_mili)
{
    entities->coord.x += (entities->dir.y / 500.0) * tim_mili;
    entities->coord.y += (-entities->dir.x / 500.0) * tim_mili;
}

void new_moove_left(entities_t *entities, sfInt32 tim_mili)
{
    entities->coord.x -= (entities->dir.y / 500.0) * tim_mili;
    entities->coord.y -= (-entities->dir.x / 500.0) * tim_mili;
}

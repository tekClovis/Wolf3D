/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** weapons
*/
#include "call_csfml.h"
#include "game.h"
#include "my.h"
#include "entities.h"

static
void decrease_life(player_t *player, ennemies_t *ent, size_t damage,
    ennemies_t *shooter)
{
    if (shooter == NULL){
        player->property->life -= damage;
        return;
    }
    ent->property->life -= damage;
}

int knife_shoot(list_t *ennemies, player_t *player, ennemies_t *shooter,
    game_handler_t *g_h)
{
    ennemies_t *entities_touch = NULL;

    if (shooter == NULL && !launch_p_shoot(player->inventory, 700.0, g_h,
        SO_KNIFE))
        return 0;
    if (shooter != NULL && !launch_e_shoot(shooter, 700.0, g_h,
        SO_KNIFE))
        return 0;
    if (shooter == NULL)
        entities_touch = search_entity(ennemies, player, g_h);
    decrease_life(player, entities_touch, D_MINIGUN, shooter);
    return 0;
}

int gun_shoot(list_t *ennemies, player_t *player, ennemies_t *shooter,
    game_handler_t *g_h)
{
    ennemies_t *entities_touch = NULL;

    if (shooter == NULL && !launch_p_shoot(player->inventory, 700.0, g_h,
        SO_GUN))
        return 0;
    if (shooter != NULL && !launch_e_shoot(shooter, 700.0, g_h,
        SO_GUN))
        return 0;
    if (shooter == NULL)
        entities_touch = search_entity(ennemies, player, g_h);
    decrease_life(player, entities_touch, D_MINIGUN, shooter);
    return 0;
}

int shotgun_shoot(list_t *ennemies, player_t *player, ennemies_t *shooter,
    game_handler_t *g_h)
{
    ennemies_t *entities_touch = NULL;

    if (shooter == NULL && !launch_p_shoot(player->inventory, 700.0, g_h,
        SO_SHOTGUN))
        return 0;
    if (shooter == NULL)
        entities_touch = search_entity(ennemies, player, g_h);
    decrease_life(player, entities_touch, D_MINIGUN, shooter);
    return 0;
}

int minigun_shoot(list_t *ennemies, player_t *player, ennemies_t *shooter,
    game_handler_t *g_h)
{
    ennemies_t *entities_touch = NULL;

    if (shooter == NULL && !launch_p_shoot(player->inventory, 100.0, g_h,
        SO_GUN))
        return 0;
    if (shooter != NULL && !launch_e_shoot(shooter, 100.0, g_h,
        SO_GUN))
        return 0;
    if (shooter == NULL)
        entities_touch = search_entity(ennemies, player, g_h);
    decrease_life(player, entities_touch, D_MINIGUN, shooter);
    return 0;
}

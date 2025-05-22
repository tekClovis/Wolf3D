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
void decrease_life(game_handler_t *g_h, ennemies_t *ent, size_t damage,
    ennemies_t *shooter)
{
    if (shooter != NULL){
        g_h->game->ent->player->property->life -= damage;
        return;
    }
    if (ent == NULL || ent->property->life < 0)
        return;
    manage_ennemi_touch(ent, damage, g_h);
}

int knife_shoot(player_t *player, ennemies_t *shooter, game_handler_t *g_h)
{
    ennemies_t *entities_touch = NULL;

    if (shooter == NULL && !launch_p_shoot(player->inventory, 700.0, g_h,
        SO_KNIFE))
        return 0;
    if (shooter == NULL)
        entities_touch = shoot_ray(g_h, player->property);
    decrease_life(g_h, entities_touch, D_KNIFE, shooter);
    return 0;
}

int gun_shoot(player_t *player, ennemies_t *shooter, game_handler_t *g_h)
{
    ennemies_t *entities_touch = NULL;

    if (shooter == NULL && !launch_p_shoot(player->inventory, 700.0, g_h,
        SO_GUN))
        return 0;
    if (shooter != NULL && !launch_e_shoot(shooter, 700.0, g_h,
        SO_GUN))
        return 0;
    if (shooter == NULL)
        entities_touch = shoot_ray(g_h, player->property);
    decrease_life(g_h, entities_touch, D_GUN, shooter);
    return 0;
}

int shotgun_shoot(player_t *player, ennemies_t *shooter, game_handler_t *g_h)
{
    ennemies_t *entities_touch = NULL;

    if (shooter == NULL && !launch_p_shoot(player->inventory, 1100.0, g_h,
        SO_SHOTGUN))
        return 0;
    if (shooter == NULL)
        entities_touch = shoot_ray(g_h, player->property);
    decrease_life(g_h, entities_touch, D_SHOTGUN, shooter);
    return 0;
}

int minigun_shoot(player_t *player, ennemies_t *shooter, game_handler_t *g_h)
{
    ennemies_t *entities_touch = NULL;

    if (shooter == NULL && !launch_p_shoot(player->inventory, 100.0, g_h,
        SO_GUN))
        return 0;
    if (shooter != NULL && !launch_e_shoot(shooter, 100.0, g_h,
        SO_GUN))
        return 0;
    if (shooter == NULL)
        entities_touch = shoot_ray(g_h, player->property);
    decrease_life(g_h, entities_touch, D_MINIGUN, shooter);
    return 0;
}

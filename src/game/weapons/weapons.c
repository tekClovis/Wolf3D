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
void anim_little_death(ennemies_t *ent)
{
    ent->property->img->rect.top = ent->property->img->rect.height * 5;
    ent->property->img->rect.left =
        ent->property->img->rect.width * 2;
    sfClock_restart(ent->clock_touch.clock);
}

void anim_big_death(ennemies_t *ent)
{
    ent->property->img->rect.top = ent->property->img->rect.height * 2;
    ent->property->img->rect.left = 0;
    sfClock_restart(ent->clock_touch.clock);
}

static
void manage_ennemi_touch(ennemies_t *ent, size_t damage)
{
    ent->property->life -= damage;
    if (ent->property->life < 0){
        if (ent->property->id == ID_BRUT)
            anim_big_death(ent);
        if (ent->property->id != ID_BRUT)
            anim_little_death(ent);
        return;
    }
    if (ent->property->id == ID_BRUT)
        return;
    ent->clock_touch.time = sfClock_getElapsedTime
        (ent->clock_touch.clock);
    if (ent->clock_touch.time.microseconds / 1000.0 > 100.0){
        ent->property->img->rect.left =
        ent->property->img->rect.width * ent->anim;
        ent->anim = (ent->anim + 1) % 2;
        ent->property->img->rect.top = ent->property->img->rect.height * 5;
        sfClock_restart(ent->clock_touch.clock);
    }
}

static
void decrease_life(player_t *player, ennemies_t *ent, size_t damage,
    ennemies_t *shooter)
{
    if (shooter != NULL){
        player->property->life -= damage;
        return;
    }
    if (ent == NULL)
        return;
    manage_ennemi_touch(ent, damage);
}

int knife_shoot(list_t *ennemies, player_t *player, ennemies_t *shooter,
    game_handler_t *g_h)
{
    ennemies_t *entities_touch = NULL;

    if (shooter == NULL && !launch_p_shoot(player->inventory, 700.0, g_h,
        SO_KNIFE))
        return 0;
    if (shooter == NULL)
        entities_touch = search_entity(ennemies, player, g_h);
    decrease_life(player, entities_touch, D_KNIFE, shooter);
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
    decrease_life(player, entities_touch, D_GUN, shooter);
    return 0;
}

int shotgun_shoot(list_t *ennemies, player_t *player, ennemies_t *shooter,
    game_handler_t *g_h)
{
    ennemies_t *entities_touch = NULL;

    if (shooter == NULL && !launch_p_shoot(player->inventory, 1100.0, g_h,
        SO_SHOTGUN))
        return 0;
    if (shooter == NULL)
        entities_touch = search_entity(ennemies, player, g_h);
    decrease_life(player, entities_touch, D_SHOTGUN, shooter);
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

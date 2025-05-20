/*
** EPITECH PROJECT, 2025
** Wolf3D
** File description:
** animation_weapons
*/

#include "game.h"

void animate_gun(game_handler_t *g_h, gun_t *gun)
{
    inventory_t *inv = g_h->game->ent->player->inventory;
    sfTime time = sfClock_getElapsedTime(g_h->game->hud->animation);
    float second = time.microseconds / 1000000.0;

    if (second > 0.05) {
        if (gun->img->rect.left <= 256)
            gun->img->rect.left += 65;
        if (gun->img->rect.left > 256){
            gun->img->rect.left = 1;
            g_h->game->hud->anim = false;
        }
        sfSprite_setTextureRect(gun->img->sprite, gun->img->rect);
        sfClock_restart(g_h->game->hud->animation);
    }
}

void animate_shgun(game_handler_t *g_h, gun_t *shotgun)
{
    sfTime time = sfClock_getElapsedTime(g_h->game->hud->animation);
    float second = time.microseconds / 1000000.0;

    if (second > 0.1) {
        if (shotgun->img->rect.left <= 1000 && g_h->game->hud->anim)
            shotgun->img->rect.left += 500;
        if (shotgun->img->rect.left > 1400 && shotgun->img->rect.top == 420) {
            g_h->game->hud->anim = false;
            shotgun->img->rect.left = 0;
            shotgun->img->rect.top = 0;
        }
        if (shotgun->img->rect.left > 1400 && shotgun->img->rect.top == 0) {
            shotgun->img->rect.left = 0;
            shotgun->img->rect.top = 420;
        }
        sfSprite_setTextureRect(shotgun->img->sprite, shotgun->img->rect);
        sfClock_restart(g_h->game->hud->animation);
    }
}

void animate_minigun(game_handler_t *g_h, gun_t *gun)
{
    inventory_t *inv = g_h->game->ent->player->inventory;
    sfTime time = sfClock_getElapsedTime(g_h->game->hud->animation);
    float second = time.microseconds / 1000000.0;

    if (second > 0.025) {
        if (gun->img->rect.left <= 240)
            gun->img->rect.left += 80;
        if (gun->img->rect.left > 240){
            gun->img->rect.left = 80;
            g_h->game->hud->anim = false;
        }
        sfSprite_setTextureRect(gun->img->sprite, gun->img->rect);
        sfClock_restart(g_h->game->hud->animation);
    }
}

/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** init_weapons
*/

#include "game.h"

gun_t *init_knife(game_handler_t *g_h)
{
    gun_t *knife = malloc(sizeof(gun_t));

    knife->img = set_img(T_3D_KNIFE, (sfIntRect){0, 0, 64, 64},
        (sfVector2f){0, 0}, g_h);
    knife->ammo = 0;
    knife->mag_cap = 10;
    knife->magazine = knife->mag_cap;
    knife->shoot_so = get_sound(g_h->sound, SO_KNIFE);
    //knife->gun_shot = &knife_shoot;
    return knife;
}

gun_t *init_gun(game_handler_t *g_h)
{
    gun_t *gun = malloc(sizeof(gun_t));

    gun->img = set_img(T_3D_GUN, (sfIntRect){0, 0, 64, 64},
        (sfVector2f){0, 0}, g_h);
    if (!load_from_file(g_h, "gun_ammo.bin", &gun->ammo, sizeof(gun->ammo)))
        gun->ammo = 60;
    gun->mag_cap = 8;
    gun->magazine = gun->mag_cap;
    gun->shoot_so = get_sound(g_h->sound, SO_GUN);
    //gun->gun_shot = &gun_shoot;
    return gun;
}

gun_t *init_shotgun(game_handler_t *g_h)
{
    gun_t *shotgun = malloc(sizeof(gun_t));

    shotgun->img = set_img(T_3D_SHOTGUN, (sfIntRect){0, 0, 64, 64},
        (sfVector2f){0, 0}, g_h);
    if (!load_from_file(g_h, "shotgun_ammo.bin", &shotgun->ammo,
        sizeof(shotgun->ammo)))
        shotgun->ammo = 20;
    shotgun->mag_cap = 5;
    shotgun->magazine = shotgun->mag_cap;
    shotgun->shoot_so = get_sound(g_h->sound, SO_SHOTGUN);
    //shotgun->gun_shot = &shotgun_shoot;
    return shotgun;
}

gun_t *init_minigun(game_handler_t *g_h)
{
    gun_t *minigun = malloc(sizeof(gun_t));

    minigun->img = set_img(T_3D_MINIGUN, (sfIntRect){0, 0, 81, 75},
        (sfVector2f){0, 0}, g_h);
    if (!load_from_file(g_h, "minigun_ammo.bin", &minigun->ammo,
        sizeof(minigun->ammo)))
        minigun->ammo = 200;
    minigun->mag_cap = 100;
    minigun->magazine = minigun->mag_cap;
    minigun->shoot_so = get_sound(g_h->sound, SO_SHOTGUN);
    //shotgun->gun_shot = &shotgun_shoot;
    return minigun;
}

gun_t **init_weapons(game_handler_t *g_h)
{
    gun_t **guns = malloc(sizeof(gun_t *) * NB_GUN);

    if (guns == NULL)
        return NULL;
    guns[W_ID_KNIFE] = init_knife(g_h);
    guns[W_ID_GUN] = init_gun(g_h);
    guns[W_ID_SHOTGUN] = init_shotgun(g_h);
    guns[W_ID_MINIGUN] = init_minigun(g_h);
    return guns;
}

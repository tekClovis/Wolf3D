/*
** EPITECH PROJECT, 2025
** G-ING-210-REN-2-1-wolf3d-clovis.nedelec
** File description:
** init_player_ennemies
*/
#include "game.h"
#include "entities.h"

int init_player(player_t *player)
{
    player->angle = 0;
    player->property = (entities_class_t){.coord = (sfVector2f){0, 0},
    .sprite = NULL, .texture = NULL,
        .life = 100, .speed = 0};
    return 0;
}

void set_ss(ennemies_t *ennemi, sfVector2f coord)
{
    ennemi->property.angle = rand() % 360;
    ennemi->property.life = 100;
    ennemi->property.speed = 200;
    ennemi->property.clock.clock = sfClock_create();
    ennemi->property.coord = coord;
    ennemi->property.texture =
    sfTexture_createFromFile("img/SS_ennemies.png", NULL);
    ennemi->property.sprite =
    sfSprite_create();
    sfSprite_setPosition(ennemi->property.sprite, (sfVector2f){0, 0});
    sfSprite_setScale(ennemi->property.sprite, (sfVector2f){1, 1});
    sfSprite_setTextureRect(ennemi->property.sprite,
        (sfIntRect){0, 0, 65, 65});
    //ennemi->gun_shot = &pistol_gun;
}

void init_enemies(ennemies_t *ennemies, sfVector2f coord, int id)
{
    if (id == SS)
        set_ss(ennemies, coord);
    else if (id == MUTANT)
        set_mutant(ennemies);
    else
        set_brut(ennemies);
}

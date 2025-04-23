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
        .life = 100, .speed = 0, .hb_2d = (sfVector2f){10, 10}};
    return 0;
}

void set_ss(ennemies_t *ennemi, sfVector2f coord)
{
    ennemi->property = (entities_class_t){.angle = rand() % 360,
        .life = 100, .speed = 125, .clock = sfClock_create(),
        .coord = coord, .sprite = sfSprite_create(),
        .texture = sfTexture_createFromFile("img/SS_ennemies.png", NULL),
        .hb_2d = (sfVector2f){10, 10}, .id = SS};
    sfSprite_setPosition(ennemi->property.sprite, (sfVector2f){0, 0});
    sfSprite_setScale(ennemi->property.sprite, (sfVector2f){1, 1});
    sfSprite_setTextureRect(ennemi->property.sprite,
        (sfIntRect){0, 0, 65, 65});
    //ennemi->gun_shot = &pistol_gun;
}

void set_mutant(ennemies_t *ennemi, sfVector2f coord)
{
    ennemi->property = (entities_class_t){.angle = rand() % 360,
        .life = 150, .speed = 200, .clock = sfClock_create(),
        .coord = coord, .sprite = sfSprite_create(),
        .texture = sfTexture_createFromFile("img/Mutant.png", NULL),
        .hb_2d = (sfVector2f){10, 10}, .id = MUTANT};
    sfSprite_setPosition(ennemi->property.sprite, (sfVector2f){0, 0});
    sfSprite_setScale(ennemi->property.sprite, (sfVector2f){1, 1});
    sfSprite_setTextureRect(ennemi->property.sprite,
        (sfIntRect){0, 0, 65, 65});
    //ennemi->gun_shot = &assault_gun;
}

void set_brut(ennemies_t *ennemi, sfVector2f coord)
{
    ennemi->property = (entities_class_t){.angle = rand() % 360,
        .life = 300, .speed = 75, .clock = sfClock_create(),
        .coord = coord, .sprite = sfSprite_create(),
        .texture = sfTexture_createFromFile("img/Brut.png", NULL),
        .hb_2d = (sfVector2f){15, 15}, .id = BRUT};
    sfSprite_setPosition(ennemi->property.sprite, (sfVector2f){0, 0});
    sfSprite_setScale(ennemi->property.sprite, (sfVector2f){1, 1});
    sfSprite_setTextureRect(ennemi->property.sprite,
        (sfIntRect){0, 0, 65, 65});
    //ennemi->gun_shot = &mini_gun; fairre un rand() % dist pour la dispersion des balles
}

void init_enemies(ennemies_t *ennemies, sfVector2f coord, int id)
{
    if (id == SS)
        set_ss(ennemies, coord);
    else if (id == MUTANT)
        set_mutant(ennemies, coord);
    else
        set_brut(ennemies, coord);
}

/*
** EPITECH PROJECT, 2025
** G-ING-210-REN-2-1-wolf3d-clovis.nedelec
** File description:
** init_player_ennemies
*/
#include "game.h"
#include "entities.h"
#include "init.h"

static
entities_t *init_entities(sfVector2f coord, sfVector2f h_b, size_t id,
    img_t *img)
{
    entities_t *entities = malloc(sizeof(entities));

    if (entities == NULL)
        return NULL;
    entities->img = img;
    entities->id = id;
    entities->angle = 0;
    entities->speed = WALK;
    entities->hb_2d = h_b;
    entities->clock = init_clock();
    return entities;
}

static
inventory_t *init_inventory(game_handler_t *g_h)
{
    inventory_t *inventory = malloc(sizeof(inventory_t));

    if (inventory == NULL)
        return NULL;
    inventory->gun = malloc(sizeof(gun_t) * NB_GUN);
    if (!load_from_file(g_h, "nb_gun.bin",
        &inventory->nb_of_gun, sizeof(inventory->nb_of_gun)))
        inventory->nb_of_gun = 1;
    inventory->actual_gun = W_ID_KNIFE;
    inventory->gun = init_guns();
    return inventory;
}

bool init_player(game_handler_t *g_h)
{
    g_h->game->ent->player->property = init_entities((sfVector2f){0, 0},
        (sfVector2f){10, 10}, ID_PLAYER, set_img(T_P_2D,
            (sfIntRect){0, 0, 0, 0}, (sfVector2f){0, 0}, g_h));
    g_h->game->ent->player->clock_sound = init_clock();
    g_h->game->ent->player->inventory = init_inventory(g_h);
    if (g_h->game->ent->player->inventory == NULL)
        return false;
    g_h->game->ent->player->life = 100;
    if (!load_from_file(g_h, "life.bin",
        &g_h->game->ent->player->life, sizeof(int)))
        g_h->game->ent->player->life = 100;
    return true;
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

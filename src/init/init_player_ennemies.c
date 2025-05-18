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
    entities->dir = (sfVector2f){-1.0, 0.0};
    entities->plan = (sfVector2f){0.0, 0.66};
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
    inventory->gun = init_weapons(g_h);
    inventory->clock_refill = init_clock();
    inventory->clock_shoot = init_clock();
    return inventory;
}

bool init_player(game_handler_t *g_h)
{
    g_h->game->ent->player->property = init_entities((sfVector2f){5, 5},
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

static
ennemies_t *set_ss(game_handler_t *g_h, ennemies_t *ennemi,
    sfVector2f coord)
{
    ennemi->property = init_entities(coord, (sfVector2f){20, 20}, ID_SS,
        set_img(T_SS, (sfIntRect){0, 0, 65, 65}, coord, g_h));
    ennemi->clock_sound = init_clock();
    ennemi->life = 100;
    ennemi->speed = WALK + 25;
    //ennemi->gun_shot = &pistol_gun;
    return ennemi;
}

static
ennemies_t *set_mutant(game_handler_t *g_h, ennemies_t *ennemi,
    sfVector2f coord)
{
    ennemi->property = init_entities(coord, (sfVector2f){20, 20}, ID_MUTANT,
        set_img(T_MUTANT, (sfIntRect){0, 0, 65, 65}, coord, g_h));
    ennemi->clock_sound = init_clock();
    ennemi->life = 150;
    ennemi->speed = RUN;
    //ennemi->gun_shot = &assault_gun;
    return ennemi;
}

static
ennemies_t *set_brut(game_handler_t *g_h, ennemies_t *ennemi,
    sfVector2f coord)
{
    ennemi->property = init_entities(coord, (sfVector2f){20, 20}, ID_BRUT,
        set_img(T_BRUT, (sfIntRect){0, 0, 65, 65}, coord, g_h));
    ennemi->clock_sound = init_clock();
    ennemi->life = 200;
    ennemi->speed = WALK - 25;
    /*ennemi->gun_shot = &mini_gun; fairre un rand() % dist pour
    la dispersion des balles*/
    return ennemi;
}

bool init_enemies(game_handler_t *g_h, sfVector2f coord, int id)
{
    ennemies_t *ennemies = malloc(sizeof(ennemies_t));
    
    if (ennemies == NULL)
        return fprintf(2, "malloc error"), false;
    if (id == ID_SS)
        ennemies = set_ss(g_h, ennemies, coord);
    if (id == ID_MUTANT)
        ennemies = set_mutant(g_h, ennemies, coord);
    if (id == ID_BRUT)
        ennemies = set_brut(g_h, ennemies, coord);
    if (ennemies == NULL)
        return fprintf(2, "no ennemi id"), false;
    push_back(g_h->game->ent->entities, ennemies->property);
    push_back(g_h->game->ent->ennemies, ennemies);
    return true;
}

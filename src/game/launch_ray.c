/*
** EPITECH PROJECT, 2025
** G-ING-210-REN-2-1-wolf3d-clovis.nedelec
** File description:
** launch_ray
*/
#include "game.h"


bool is_between_point(sfVector2f entity_pos,
    sfVector2f start_point, sfVector2f end_point)
{
    float error = 1.0f;
    float dx1 = end_point.x - start_point.x;
    float dy1 = end_point.y - start_point.y;
    float dx2 = entity_pos.x - start_point.x;
    float dy2 = entity_pos.y - start_point.y;
    float cross = dx1 * dy2 - dy1 * dx2;
    float dot = 0;
    float len_sq = 0;

    if (fabs(cross) > error)
        return false;
    dot = dx2 * dx1 + dy2 * dy1;
    if (dot < 0)
        return false;
    len_sq = dx1 * dx1 + dy1 * dy1;
    if (dot > len_sq)
        return false;
    return true;
}

/*
on fait une recursion sur node next
on garde toujours player_co car elle ne change jamais
wall_co correspond a la coord
on récupere les coords de l' entité dans la node
*/
static
bool find_the_closer(entities_t *ent,
    sfVector2f player_co, sfVector2f wall_co)
{
    if (ent == NULL)
        return false;
    if (is_between_point(ent->coord, player_co, wall_co) == true)
        return true;
    return false;
}

bool search_player(game_handler_t *game, entities_t *ennemie)
{
    int x = 0;

    init_ray_cast(&game->ray_cast, ennemie, x);
    prep_dda(&game->ray_cast, ennemie);
    execute_dda(&game->ray_cast,
        game->game->level.map[game->game->level.actual_level]);
    return find_the_closer(ennemie,
        game->game->ent->player->property->coord,
        (sfVector2f){(float)game->ray_cast.map_x,
        (float)game->ray_cast.map_y});
}

static
ennemies_t *find_the_closer_en(node_t *node,
    sfVector2f player_co, sfVector2f wall_co)
{
    ennemies_t *ennemi = NULL;

    if (node == NULL)
        return NULL;
    ennemi = (ennemies_t *)node->data;
    if (is_between_point(ennemi->property->coord, player_co, wall_co) == true)
        return ennemi;
    return find_the_closer_en(node->next, player_co, wall_co);
}

ennemies_t *shoot_ray(game_handler_t *game, entities_t *player)
{
    int x = WIDTH / 2;

    init_ray_cast(&game->ray_cast, game->game->ent->player->property, x);
    prep_dda(&game->ray_cast, player);
    execute_dda(&game->ray_cast,
        game->game->level.map[game->game->level.actual_level]);
    return find_the_closer_en(game->game->ent->ennemies->head,
        player->coord, (sfVector2f){(float)game->ray_cast.map_x,
        (float)game->ray_cast.map_y});
}

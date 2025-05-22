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
entities_t *find_the_closer(node_t *node,
    sfVector2f player_co, sfVector2f wall_co)
{
    entities_t *entitie = NULL;
    draw_sprite_t draw_ent = {0};

    if (node == NULL)
        return NULL;
    entitie = (entities_t *)node->data;
    if (is_between_point(entitie->coord, player_co, wall_co) == true)
        return entitie;
    return find_the_closer(node->next, player_co, wall_co);
}

entities_t *launch_ray(game_handler_t *game, entities_t *player)
{
    int x = WIDTH / 2;

    init_ray_cast(&game->ray_cast, game->game->ent->player->property, x);
    prep_dda(&game->ray_cast, player);
    execute_dda(&game->ray_cast,
        game->game->level.map[game->game->level.actual_level]);
    return find_the_closer(game->game->ent->entities->head,
        player->coord, (sfVector2f){(float)game->ray_cast.map_x,
        (float)game->ray_cast.map_y});
}

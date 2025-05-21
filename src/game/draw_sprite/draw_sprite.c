/*
** EPITECH PROJECT, 2025
** G-ING-210-REN-2-1-wolf3d-clovis.nedelec
** File description:
** draw_sprite
*/

#include "game.h"
#include "in_game.h"
#include "ray_casting.h"

/*
effectue plusieur calul pour déterminer la position
de l' entité par rapport a la position du joueur
renvoie true si l' ennemie est dans la zone vu par le plan
camera determiner pas la vecteur direction du joueur
*/
bool fill_draw_ent(draw_sprite_t *draw_ent, entities_t *entities, entities_t *player)
{
    draw_ent->sprite_coord.x = entities->coord.x - player->coord.x;
    draw_ent->sprite_coord.y = entities->coord.y - player->coord.y;
    draw_ent->inv_mat = 1.0f / 
        (player->plan.x * player->dir.y - player->dir.x * player->plan.y);
    draw_ent->transform.x = draw_ent->inv_mat * 
        (player->dir.y * draw_ent->sprite_coord.x -
        player->dir.x * draw_ent->sprite_coord.y);
    draw_ent->transform.y = draw_ent->inv_mat *
        (-player->plan.y * draw_ent->sprite_coord.x +
        player->plan.x * draw_ent->sprite_coord.y);
    if (draw_ent->transform.y > 0)
            return true;
    draw_ent->sprite_screen_x = (int)((WIDTH / 2) * (1 + draw_ent->transform.x / draw_ent->transform.y));
   return false;
}

void get_size_ent(draw_sprite_t *draw_ent)
{
    int sprite_width = 0;
    int sprite_height = abs((int)(HEIGHT / (draw_ent->transform.y)));
    
    draw_ent->draw_start.y = -sprite_height / 2 + HEIGHT / 2;
    if (draw_ent->draw_start.y < 0)
        draw_ent->draw_start.y = 0;
    draw_ent->draw_end.y = sprite_height / 2 + HEIGHT / 2;
    if (draw_ent->draw_end.y >= HEIGHT) 
        draw_ent->draw_end.y  = HEIGHT - 1;
    sprite_width = abs((int) (HEIGHT / (draw_ent->transform.y)));

    draw_ent->draw_start.x = -sprite_width / 2 + draw_ent->sprite_screen_x;
    if (draw_ent->draw_start.x < 0) 
        draw_ent->draw_start.x = 0;
    draw_ent->draw_end.x = sprite_width / 2 + draw_ent->sprite_screen_x;
    if(draw_ent->draw_end.x >= WIDTH) 
        draw_ent->draw_end.x = WIDTH - 1;
}

void draw_one_ent(entities_t *entities, draw_sprite_t *draw_ent)
{
    get_size_ent(draw_ent);
}

/*
Parcour recursife de la liste chainé
en commencant par la head et en suivant les nexts
-----
draw sprite me permet d' effectuer tous les calcul
*/
void draw_lkd_sprite(node_t *node, entities_t *player, sfRenderWindow *window, double buffer_z[WIDTH])
{
    entities_t *entitie = NULL;
    draw_sprite_t draw_ent = {0};

    if (node == NULL)
        return;
    entitie = (entities_t *)node->data;
    if (fill_draw_ent(&draw_ent, entitie, player) == false)
        return draw_lkd_sprite(node->next, player, window, buffer_z);
    draw_one_ent(entitie, &draw_ent);
    return draw_lkd_sprite(node->next, player, window, buffer_z);
}

/*permet d' afficher tous les sprite
en effectuant la fonction de sort par
rapport a la distance sans sqrt
puis lance une fonction recursive
qui calcul si on peut draw le sprite et le display.*/
void draw_sprite(game_handler_t *game, sfRenderWindow *window)
{
    node_t *node = (node_t *)game->game->ent->entities->head;
    entities_t *player = game->game->ent->player->property;
    
    /*sort_sprite(game->game->ent->entities->head)*/
    draw_lkd_sprite(node, player, window, game->ray_cast.z_buffer);
    return;
}

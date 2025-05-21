/*
** EPITECH PROJECT, 2025
** G-ING-210-REN-2-1-wolf3d-clovis.nedelec
** File description:
** run_game
*/

#include "game.h"
#include "ray_casting.h"

static
void rotate_right(entities_t *player, float rot_speed)
{
    float old_dir_x = 0;
    float old_plane_x = 0;


    old_dir_x = player->dir.x;
    player->dir.x = player->dir.x * cos(-rot_speed) -
    player->dir.y * sin(-rot_speed);
    player->dir.y = old_dir_x * sin(-rot_speed) + player->dir.y
    * cos(-rot_speed);
    old_plane_x = player->plan.x;
    player->plan.x = player->plan.x * cos(-rot_speed)
    - player->plan.y * sin(-rot_speed);
    player->plan.y = old_plane_x * sin(-rot_speed) + player->plan.y
    * cos(-rot_speed);
}

static
void rotate_left(entities_t *player, float rot_speed)
{
    float old_dir_x = 0;
    float old_plane_x = 0;

    old_dir_x = player->dir.x;
    player->dir.x = player->dir.x * cos(rot_speed)
    - player->dir.y * sin(rot_speed);
    player->dir.y = old_dir_x * sin(rot_speed) +
    player->dir.y * cos(rot_speed);
    old_plane_x = player->plan.x;
    player->plan.x = player->plan.x * cos(rot_speed)
    - player->plan.y * sin(rot_speed);
    player->plan.y = old_plane_x * sin(rot_speed)
    + player->plan.y * cos(rot_speed);
}

void new_rotate_player(entities_t *player, float rot_speed, sfInt32 time, sfEvent *event)
{
    if (sfKeyboard_isKeyPressed(sfKeyLeft))
        rotate_left(player, rot_speed * time);
    if (sfKeyboard_isKeyPressed(sfKeyRight))
        rotate_right(player, rot_speed * time);
}

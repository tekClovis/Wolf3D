/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** handle_ent_event
*/
#include "game.h"
#include "entities.h"

static
void check_w_switch(game_handler_t *g_h, player_t *player)
{
    if ((g_h->event->key.code == sfKeyA &&
        g_h->event->type == sfEvtKeyPressed) || check_l1()){
        player->inventory->actual_gun -= 1;
        if (player->inventory->actual_gun < 0)
            player->inventory->actual_gun = player->inventory->nb_of_gun - 1;
    }
    if ((g_h->event->key.code == sfKeyE &&
        g_h->event->type == sfEvtKeyPressed) || check_r1())
        player->inventory->actual_gun =
        (player->inventory->actual_gun + 1) % player->inventory->nb_of_gun;
}

static
void check_reload(game_handler_t *g_h, inventory_t *inv)
{
    int to_refill = inv->gun[inv->actual_gun]->mag_cap -
        inv->gun[inv->actual_gun]->magazine;

    if ((g_h->event->key.code == sfKeyR &&
        g_h->event->type == sfEvtKeyPressed) || check_square()){
        if (inv->gun[inv->actual_gun]->ammo <
            inv->gun[inv->actual_gun]->mag_cap){
            inv->gun[inv->actual_gun]->magazine
            = inv->gun[inv->actual_gun]->ammo;
            inv->gun[inv->actual_gun]->ammo = 0;
        }
        if (inv->gun[inv->actual_gun]->ammo >=
            inv->gun[inv->actual_gun]->mag_cap){
            inv->gun[inv->actual_gun]->magazine
            = inv->gun[inv->actual_gun]->mag_cap;
            inv->gun[inv->actual_gun]->ammo -= to_refill;
        }
    }
}

static
void handle_player(game_handler_t *g_h, player_t *player)
{
    if ((g_h->event->key.code == sfKeySpace &&
        g_h->event->type == sfEvtKeyPressed) || check_cross())
        player->is_shooting = true;
    if ((g_h->event->key.code == sfKeySpace &&
        g_h->event->type == sfEvtKeyReleased) || check_cross())
        player->is_shooting = false;
    check_w_switch(g_h, player);
    check_reload(g_h, player->inventory);
}

static
void handle_menu(game_handler_t *g_h)
{
    if (g_h->event->key.code == sfKeyEscape &&
            g_h->event->type == sfEvtKeyPressed){
            g_h->screen_mode = S_MENU;
            g_h->screen->act_menu = M_PAUSE;
            sfMusic_stop(g_h->game->game_music);
            sfMusic_play(g_h->screen->menu_music);
    }
}

void handle_game_event(game_handler_t *g_h)
{
    if (sfClock_getElapsedTime(g_h->game->hud->level_launch.clock)
        .microseconds / 1000.0 < 3000.0)
        return;
    handle_player(g_h, g_h->game->ent->player);
    handle_menu(g_h);
}

/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** handle_ent_event
*/
#include "game.h"
#include "entities.h"

static
void handle_player(game_handler_t *g_h, player_t *player)
{
    return;
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
    handle_player(g_h, g_h->game->ent->player);
    handle_menu(g_h);
}

/*
** EPITECH PROJECT, 2025
** Wolf3D
** File description:
** hud
*/

#include "game.h"
#include "stdio.h"

static void set_int_in_text(int value, sfText *text)
{
    char buffer[12];
    sfFloatRect bounds;

    snprintf(buffer, sizeof(buffer), "%d", value);
    sfText_setString(text, buffer);
    bounds = sfText_getLocalBounds(text);
    sfText_setOrigin(text, (sfVector2f){
        bounds.left + bounds.width / 2.0f,
        bounds.top + bounds.height / 2.0f
    });
}

static void set_catint_in_text(int value, sfText *text, char *str)
{
    char buffer[19];
    sfFloatRect bounds;

    snprintf(buffer, sizeof(buffer), "%s%d", str, value);
    sfText_setString(text, buffer);
    bounds = sfText_getLocalBounds(text);
    sfText_setOrigin(text, (sfVector2f){
        bounds.left + bounds.width / 2.0f,
        bounds.top + bounds.height / 2.0f
    });
}

void update_assets(hud_t *hud, game_handler_t *g_h)
{
    game_t *game = g_h->game;
    int actual_gun = game->ent->player->inventory->actual_gun;

    set_catint_in_text(game->score.score, hud->score, "Score : ");
    set_int_in_text(game->ent->player->property->life, hud->life);
    set_int_in_text(game->ent->player->inventory->gun[actual_gun]->ammo,
    hud->ammo);
    set_int_in_text(game->ent->player->inventory->gun[actual_gun]->magazine,
    hud->magazine);
    set_catint_in_text(g_h->general_clock.time_as_second,
        hud->time, "Time : ");
    sfRenderWindow_drawSprite(g_h->screen->win,
        hud->weapon_two_d[actual_gun]->sprite, NULL);
}

void draw_hud(hud_t *hud, game_handler_t *g_h)
{
    inventory_t *inv = g_h->game->ent->player->inventory;

    if (sfKeyboard_isKeyPressed(sfKeyA)) {
        g_h->game->score.score++;
        g_h->game->ent->player->property->life--;
        g_h->game->ent->player->inventory->actual_gun++;
        if (g_h->game->ent->player->inventory->actual_gun > 3)
            g_h->game->ent->player->inventory->actual_gun = 0;
    }
    sfRenderWindow_drawSprite(g_h->screen->win,
        inv->gun[inv->actual_gun]->img->sprite, NULL);
    sfRenderWindow_drawSprite(g_h->screen->win, hud->bg_player_info->sprite,
        NULL);
    update_assets(hud, g_h);
    sfRenderWindow_drawText(g_h->screen->win, hud->score, NULL);
    sfRenderWindow_drawText(g_h->screen->win, hud->time, NULL);
    sfRenderWindow_drawText(g_h->screen->win, hud->magazine, NULL);
    sfRenderWindow_drawText(g_h->screen->win, hud->life, NULL);
    sfRenderWindow_drawText(g_h->screen->win, hud->ammo, NULL);
}

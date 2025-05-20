/*
** EPITECH PROJECT, 2025
** Wolf3D
** File description:
** hud
*/

#include "game.h"
#include "stdio.h"

void set_int_in_text(int value, sfText *text)
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

void set_clock_in_text(sfClock *clock, sfText *text)
{
    char buffer[12];
    sfFloatRect bounds;
    sfTime time = sfClock_getElapsedTime(clock);
    float seconds = sfTime_asSeconds(time);

    snprintf(buffer, sizeof(buffer), "%.0f", seconds);

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

    sfSprite_setScale(hud->bg_player_info->sprite, (sfVector2f){5.25, 5.25});
    sfSprite_setScale(hud->actual_weapon->sprite, (sfVector2f){9, 9});
    sfText_setScale(hud->life, (sfVector2f){1.5, 1.5});
    sfText_setScale(hud->score, (sfVector2f){1.5, 1.5});
    sfText_setScale(hud->magazine, (sfVector2f){1.5, 1.5});
    set_int_in_text(game->score.score, hud->score);
    set_int_in_text(game->ent->player->life, hud->life);
    set_int_in_text(game->ent->player->inventory->gun[actual_gun]->magazine,
    hud->magazine);
    set_clock_in_text(g_h->general_clock.clock, hud->time);
    sfRenderWindow_drawSprite(g_h->screen->win, hud->weapon_two_d[actual_gun]->sprite,
        NULL);
}

void draw_hud(hud_t *hud, game_handler_t *g_h)
{
    if (sfKeyboard_isKeyPressed(sfKeyA)) {
        g_h->game->score.score++;
        g_h->game->ent->player->life--;
        g_h->game->ent->player->inventory->actual_gun++;
        if (g_h->game->ent->player->inventory->actual_gun > 3)
            g_h->game->ent->player->inventory->actual_gun = 0;
    }
    sfRenderWindow_drawSprite(g_h->screen->win, hud->bg_player_info->sprite,
        NULL);
    update_assets(hud, g_h);
    sfRenderWindow_drawText(g_h->screen->win, hud->score, NULL);
    sfRenderWindow_drawText(g_h->screen->win, hud->time, NULL);
    sfRenderWindow_drawText(g_h->screen->win, hud->magazine, NULL);
    sfRenderWindow_drawText(g_h->screen->win, hud->life, NULL);
}
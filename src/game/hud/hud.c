/*
** EPITECH PROJECT, 2025
** Wolf3D
** File description:
** hud
*/

#include "game.h"
#include "stdio.h"

anim_t const TAB_ANIM[] = {
    {&animate_gun},
    {&animate_gun},
    {&animate_shgun},
    {&animate_minigun},
    {NULL}
};

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

    snprintf(buffer, sizeof(buffer), "%s%d", str, value);
    sfText_setString(text, buffer);
}

int get_clocktime(sfClock *clock)
{
    sfTime time = sfClock_getElapsedTime(clock);
    float seconds = sfTime_asSeconds(time);

    return (int)seconds;
}

static void check_anim_gun(game_handler_t *g_h)
{
    inventory_t *inv = g_h->game->ent->player->inventory;

    if (g_h->game->hud->anim)
        TAB_ANIM[inv->actual_gun].func(g_h, inv->gun[inv->actual_gun]);
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
    set_catint_in_text(get_clocktime(g_h->game->clock_game),
        hud->time, "Time : ");
    sfRenderWindow_drawSprite(g_h->screen->win,
        hud->weapon_two_d[actual_gun]->sprite, NULL);
}

static
void set_and_draw(sfSprite *sprite, sfVector2f scale, sfVector2f temp,
    game_handler_t *g_h)
{
    sfSprite_setScale(sprite,
        (sfVector2f){scale.x * 0.5, scale.y * 0.5});
    sfRenderWindow_drawSprite(g_h->screen->win,
        sprite, NULL);
    sfSprite_setPosition(sprite, temp);
    sfSprite_setScale(sprite, scale);
}

static
void draw_unlock_w(hud_t *hud, game_handler_t *g_h)
{
    sfVector2f temp;
    float y_base = 100;
    float y = 75;
    float x = 10;
    sfVector2f tmp_scale;

    for (int i = 0; i < g_h->game->ent->player->inventory->nb_of_gun; i++){
        temp = sfSprite_getPosition(hud->weapon_two_d[i]->sprite);
        sfSprite_setPosition(hud->weapon_two_d[i]->sprite,
            (sfVector2f){x, y_base + y * i});
        tmp_scale = sfSprite_getScale(hud->weapon_two_d[i]->sprite);
        sfSprite_setScale(hud->weapon_two_d[i]->sprite,
            (sfVector2f){tmp_scale.x * 0.5, tmp_scale.y * 0.5});
        if (i == W_ID_SHOTGUN)
            sfSprite_setPosition(hud->weapon_two_d[i]->sprite, (sfVector2f)
                {x, y_base + y * ((float)i + 0.2)});
        set_and_draw(hud->weapon_two_d[i]->sprite, tmp_scale, temp, g_h);
    }
}

void draw_hud(hud_t *hud, game_handler_t *g_h)
{
    inventory_t *inv = g_h->game->ent->player->inventory;

    check_anim_gun(g_h);
    sfRenderWindow_drawSprite(g_h->screen->win,
        inv->gun[inv->actual_gun]->img->sprite, NULL);
    sfRenderWindow_drawSprite(g_h->screen->win, hud->bg_player_info->sprite,
        NULL);
    update_assets(hud, g_h);
    draw_unlock_w(hud, g_h);
    sfRenderWindow_drawText(g_h->screen->win, hud->score, NULL);
    sfRenderWindow_drawText(g_h->screen->win, hud->time, NULL);
    sfRenderWindow_drawText(g_h->screen->win, hud->magazine, NULL);
    sfRenderWindow_drawText(g_h->screen->win, hud->life, NULL);
    sfRenderWindow_drawText(g_h->screen->win, hud->ammo, NULL);
}

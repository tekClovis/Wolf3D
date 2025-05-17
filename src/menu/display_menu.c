/*
** EPITECH PROJECT, 2025
** Wolf3D
** File description:
** display_menu
*/

#include "game.h"
#include "call_csfml.h"
#include "controller.h"

void draw_menu(menu_t *menu, game_handler_t *g_h)
{
    int len = NB_MENU;

    sfRenderWindow_drawSprite(g_h->screen->win, menu->background->sprite,
        NULL);
    for (node_t *cur = menu->boutons->head; len > 0; len--){
        sfRenderWindow_drawSprite(g_h->screen->win,
            ((bouton_t *)cur->data)->released->sprite, NULL);
        cur = cur->next;
    }
    sfRenderWindow_drawRectangleShape(g_h->screen->win,
        ((bouton_t *)menu->actual_bouton->data)->press, NULL);
}

void handle_menu_event(menu_t *menu, game_handler_t *g_h, sfEvent e)
{
    sfUint8 controller = get_left_stick();

    if ((e.key.code == sfKeyDown || controller & DOWN)){
        menu->actual_bouton = menu->actual_bouton->next;
        //sfSound_play(get_sound(g_h->sound, SO_B_MOVE));
    }
    if ((e.key.code == sfKeyUp || controller & UP)){
        menu->actual_bouton = menu->actual_bouton->prev;
        //sfSound_play(get_sound(g_h->sound, SO_B_MOVE));
    }
    if (e.key.code == sfKeyEnter || check_cross() == true){
        //sfSound_play(get_sound(g_h->sound, SO_B_CLICK));
        ((bouton_t *)menu->actual_bouton->data)->action(g_h);
    }
}

int display_menu(game_handler_t *g_h)
{
    sfEvent e;

    g_h->event = e;
    while (sfRenderWindow_pollEvent(g_h->screen->win, &e)){
        g_h->event = e;
        if (need_refresh_clock(&g_h->controller.time, 0.5)){
            g_h->controller.control = get_controller_button();
        }
        handle_menu_event(&g_h->screen->menu[g_h->screen->act_menu], g_h, e);
        applied_event(g_h->screen->win, e);
    }
    draw_menu(&g_h->screen->menu[g_h->screen->act_menu], g_h);
    return 0;
}

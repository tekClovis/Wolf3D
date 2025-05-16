/*
** EPITECH PROJECT, 2025
** Wolf3D
** File description:
** init_menu
*/

#include "game.h"

static
bouton_t *set_buttons(img_t *released, void (*action)(game_handler_t *))
{
    bouton_t *bouton = malloc(sizeof(bouton_t));

    bouton->action = action;
    bouton->released = released;
    bouton->press = sfRectangleShape_create();
    sfRectangleShape_setPosition(bouton->press,
        bouton->released->pos);
    sfRectangleShape_setSize(bouton->press,
        (sfVector2f){bouton->released->rect.width,
            bouton->released->rect.top});
    return bouton;
}

menu_t *init_menu(menu_t *menu, game_handler_t *game_h, char *title)
{
    menu->boutons = list_create();
    if (menu->boutons == NULL)
        return NULL;
    menu->background = malloc(sizeof(img_t));
    if (menu->background == NULL)
        return free(menu->boutons), NULL;
    menu->background = set_img(T_M_BG, (sfIntRect){0, 0, 0, 0},
    (sfVector2f){0, 0}, game_h);
    menu->text = set_txt(80, sfRed, (sfVector2f){87, 87}, title);
    return menu;
}

bool init_start_menu(menu_t *menu, game_handler_t *game_h)
{
    menu = init_menu(menu, game_h, "WOLF3D");
    if (menu == NULL)
        return false;
    push_back(menu->boutons,
        set_buttons(set_img(T_SAVE1, (sfIntRect){0, 0, 0, 0},
        (sfVector2f){400, 700}, game_h), &handle_save1));
    push_back(menu->boutons,
        set_buttons(set_img(T_SAVE2, (sfIntRect){0, 0, 0, 0},
        (sfVector2f){500, 700}, game_h), &handle_save2));
    push_back(menu->boutons,
        set_buttons(set_img(T_SAVE3, (sfIntRect){0, 0, 0, 0},
        (sfVector2f){500, 700}, game_h), &handle_save3));
    push_back(menu->boutons,
        set_buttons(set_img(T_SETTING, (sfIntRect){0, 0, 0, 0},
        (sfVector2f){500, 700}, game_h), &go_to_setting));
}

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

static
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

bool init_end_menu(menu_t *menu, game_handler_t *game_h)
{
    menu = init_menu(menu, game_h, "GAMEOVER");
    if (menu == NULL)
        return false;
    push_back(menu->boutons,
        set_buttons(set_img(T_B_S1, (sfIntRect){0, 0, 0, 0},
        (sfVector2f){700, 300}, game_h), &go_to_home));
    push_back(menu->boutons,
        set_buttons(set_img(T_B_EXIT, (sfIntRect){0, 0, 0, 0},
        (sfVector2f){700, 850}, game_h), &exit_game));
    menu->actual_bouton = NULL;
    return true;
}

bool init_settings_menu(menu_t *menu, game_handler_t *game_h)
{
    menu = init_menu(menu, game_h, "SETTINGS");
    if (menu == NULL)
        return false;
    push_back(menu->boutons,
        set_buttons(set_img(T_B_S1, (sfIntRect){0, 0, 0, 0},
        (sfVector2f){700, 300}, game_h), &min_vol));
    push_back(menu->boutons,
        set_buttons(set_img(T_B_S2, (sfIntRect){0, 0, 0, 0},
        (sfVector2f){700, 450}, game_h), &max_vol));
    push_back(menu->boutons,
        set_buttons(set_img(T_B_S3, (sfIntRect){0, 0, 0, 0},
        (sfVector2f){700, 600}, game_h), &min__win));
    push_back(menu->boutons,
        set_buttons(set_img(T_B_SETTINGS, (sfIntRect){0, 0, 0, 0},
        (sfVector2f){700, 850}, game_h), &max_vol));
    push_back(menu->boutons,
        set_buttons(set_img(T_B_EXIT, (sfIntRect){0, 0, 0, 0},
        (sfVector2f){700, 850}, game_h), &escape_set));
    menu->actual_bouton = NULL;
    return true;
}

bool init_pause_menu(menu_t *menu, game_handler_t *game_h)
{
    menu = init_menu(menu, game_h, "PAUSE");
    if (menu == NULL)
        return false;
    push_back(menu->boutons,
        set_buttons(set_img(T_B_SETTINGS, (sfIntRect){0, 0, 0, 0},
        (sfVector2f){700, 400}, game_h), &go_to_settings));
    push_back(menu->boutons,
        set_buttons(set_img(T_B_EXIT, (sfIntRect){0, 0, 0, 0},
        (sfVector2f){700, 750}, game_h), &exit_game));
    menu->actual_bouton = NULL;
    return true;
}

bool init_start_menu(menu_t *menu, game_handler_t *game_h)
{
    menu = init_menu(menu, game_h, "WOLF3D");
    if (menu == NULL)
        return false;
    push_back(menu->boutons,
        set_buttons(set_img(T_B_S1, (sfIntRect){0, 0, 0, 0},
        (sfVector2f){700, 300}, game_h), &handle_save1));
    push_back(menu->boutons,
        set_buttons(set_img(T_B_S2, (sfIntRect){0, 0, 0, 0},
        (sfVector2f){700, 450}, game_h), &handle_save2));
    push_back(menu->boutons,
        set_buttons(set_img(T_B_S3, (sfIntRect){0, 0, 0, 0},
        (sfVector2f){700, 600}, game_h), &handle_save3));
    push_back(menu->boutons,
        set_buttons(set_img(T_B_SETTINGS, (sfIntRect){0, 0, 0, 0},
        (sfVector2f){700, 850}, game_h), &go_to_setting));
    push_back(menu->boutons,
        set_buttons(set_img(T_B_EXIT, (sfIntRect){0, 0, 0, 0},
        (sfVector2f){700, 1000}, game_h), &exit_game));
    menu->actual_bouton = NULL;
    return true;
}

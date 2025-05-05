/*
** EPITECH PROJECT, 2025
** Wolf3D
** File description:
** display_menu
*/

#include "game.h"
#include "call_csfml.h"

void draw_menu(game_handler_t *handler)
{
    sfRenderWindow_clear(handler->window, sfBlack);
    sfRenderWindow_drawSprite(handler->window, handler->menu->sprite, NULL);
    sfRenderWindow_drawSprite(handler->window, handler->menu->sprite_threed,
        NULL);
    sfRenderWindow_drawSprite(handler->window, handler->menu->sprite_twod,
        NULL);
    sfRenderWindow_drawRectangleShape(handler->window,
        handler->menu->chose_rectangle, NULL);
}

void handle_menu_event(game_handler_t *handler)
{
    sfUint8 controller = get_left_stick();

    if ((sfKeyboard_isKeyPressed(sfKeyDown) || controller & DOWN) &&
        handler->menu->act == 1) {
        sfRectangleShape_setPosition(handler->menu->chose_rectangle,
            (sfVector2f){100, 400});
            handler->menu->act = 2;
    }
    if ((sfKeyboard_isKeyPressed(sfKeyUp) || controller & UP) &&
        handler->menu->act == 2) {
        sfRectangleShape_setPosition(handler->menu->chose_rectangle,
            (sfVector2f){100, 300});
            handler->menu->act = 1;
    }
    if (sfKeyboard_isKeyPressed(sfKeyEnter) ||
        check_cross() == true){
            handler->window_mode = handler->menu->act;
    }
}

int display_menu(game_handler_t *handler)
{
    handle_menu_event(handler);
    draw_menu(handler);
    return 0;
}

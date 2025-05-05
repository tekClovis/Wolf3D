/*
** EPITECH PROJECT, 2025
** Wolf3D
** File description:
** init_menu
*/

#include "game.h"

void init_rectangle(menu_t *menu)
{
    menu->chose_rectangle = sfRectangleShape_create();
    sfRectangleShape_setPosition(menu->chose_rectangle,
        (sfVector2f){100, 300});
    sfRectangleShape_setFillColor(menu->chose_rectangle, sfTransparent);
    sfRectangleShape_setOutlineThickness(menu->chose_rectangle, 2);
    sfRectangleShape_setOutlineColor(menu->chose_rectangle, sfRed);
    sfRectangleShape_setSize(menu->chose_rectangle, (sfVector2f){200, 60});
}

void init_menu(menu_t *menu)
{
    menu->act = 1;
    menu->sprite = sfSprite_create();
    menu->texture = sfTexture_createFromFile("menu_bg.jpg", NULL);
    menu->sprite_threed = sfSprite_create();
    menu->sprite_twod = sfSprite_create();
    menu->text_threed = sfTexture_createFromFile("mode_3D.png", NULL);
    menu->text_twod = sfTexture_createFromFile("mode_2D.png", NULL);
    sfSprite_setTexture(menu->sprite_threed, menu->text_threed, sfTrue);
    sfSprite_setTexture(menu->sprite_twod, menu->text_twod, sfTrue);
    sfSprite_setTexture(menu->sprite, menu->texture, sfTrue);
    sfSprite_setPosition(menu->sprite_threed, (sfVector2f){100, 400});
    sfSprite_setPosition(menu->sprite_twod, (sfVector2f){100, 300});
    sfSprite_setScale(menu->sprite, (sfVector2f){1.25, 1.055});
    sfSprite_setScale(menu->sprite_threed, (sfVector2f){0.25, 0.25});
    sfSprite_setScale(menu->sprite_twod, (sfVector2f){0.25, 0.25});
    init_rectangle(menu);
}

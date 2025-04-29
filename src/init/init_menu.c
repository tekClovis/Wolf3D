/*
** EPITECH PROJECT, 2025
** Wolf3D
** File description:
** init_menu
*/

#include "game.h"

void init_menu(menu_t *menu)
{
    menu->sprite = sfSprite_create();
    menu->texture = sfTexture_createFromFile("menu_bg.jpg", NULL);
    sfSprite_setTexture(menu->sprite, menu->texture, sfTrue);
    sfSprite_setScale(menu->sprite, (sfVector2f){1.25, 1.055});
}

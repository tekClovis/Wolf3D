/*
** EPITECH PROJECT, 2025
** Wolf3D
** File description:
** menu
*/

#ifndef MENU_H_
    #define MENU_H_
    #include "call_csfml.h"
typedef struct menu_s {
    sfSprite *sprite;
    sfTexture *texture;
} menu_t;
void init_menu(menu_t *menu);
#endif /* !MENU_H_ */

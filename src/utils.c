/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** utils
*/
#include "game.h"
#include "call_csfml.h"

sfText *set_txt(size_t size, sfColor color, sfVector2f position, char *str)
{
    sfText *txt = sfText_create();
    
    sfText_setFont(txt, sfFont_createFromFile("./font/alagard.ttf"));
    sfText_setCharacterSize(txt, size);
    sfText_setColor(txt, color);
    sfText_setPosition(txt, position);
    sfText_setString(txt, str);
    return txt;
}

img_t *set_img(size_t texture_token, sfIntRect rect, sfVector2f pos,
    game_handler_t *g_h)
{
    img_t *img = malloc(sizeof(img_t));

    img->rect = rect;
    img->pos = pos;
    img->sprite = sfSprite_create();
    img->texture = get_texture(g_h->texture, texture_token);
    sfSprite_setTexture(img->sprite, img->texture, false);
    if (rect.top == 0){
        img->rect = sfSprite_getTextureRect(img->sprite);
    }
    sfSprite_setTextureRect(img->sprite, img->rect);
    return img;
}

sfTexture *get_texture(tab_texture_t *tab, int token)
{
    for (int i = 0; tab[i].texture; i++)
        if (tab[i].id == token)
            return tab[i].texture;
    fprintf(2, "no texture token");
    return NULL;
}

/*
** EPITECH PROJECT, 2025
** G-ING-210-REN-2-1-wolf3d-clovis.nedelec
** File description:
** free_game
*/
#include "game.h"

static
void free_window(sfRenderWindow *window)
{
    sfRenderWindow_destroy(window);
}

static
void free_img(img_t *img)
{
    sfSprite_destroy(img->sprite);
    sfImage_destroy(img->img);
    free(img);
}

static
void free_time_manage(time_management_t *time_manage)
{
    sfClock_destroy(time_manage->clock);
}

void free_controller(controller_t *controller)
{
    free_time_manage(&controller->time);
}

void free_sound_pool(tab_sound_t **texture_sound)
{
    for (int i = 0; texture_sound[i] != NULL; i++){
        free(texture_sound[i]->file);
        sfSound_destroy(texture_sound[i]->sound);
        sfSoundBuffer_destroy(texture_sound[i]->buffer);
    }
}


void free_texture_pool(tab_texture_t **texture_tab)
{
    for (int i = 0; texture_tab[i] != NULL; i++){
        free(texture_tab[i]->file);
        sfTexture_destroy(texture_tab[i]->texture);
        sfImage_destroy(texture_tab[i]->img);
    }
}

void free_game_handler(game_handler_t *game_handler)
{
    free_controller(&game_handler->controller);
    free_texture_pool(game_handler->texture);
    free(game_handler->texture);
    free_sound_pool(game_handler->sound);
    free(game_handler->sound);
    free_screen(game_handler->screen);
    free(game_handler->screen);

    if (game_handler->game)
        free_game(game_handler);
}

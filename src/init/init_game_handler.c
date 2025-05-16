/*
** EPITECH PROJECT, 2025
** G-ING-210-REN-2-1-wolf3d-clovis.nedelec
** File description:
** init_game_handler
*/
#include "game.h"
#include "init.h"
#include "ray_casting.h"

static
int init_binary_tree(buffer_z_t **buffer_z)
{
    *buffer_z = malloc(sizeof(buffer_z_t) * WINDOW_SIZE_X);
    if (*buffer_z == NULL)
        return 84;
    return 0;
}

int init_controller(controller_t *controller)
{
    controller->control = 0;
    controller->time = init_clock();
}




static
bool init_screen(screen_t *screen, game_handler_t *game_handler)
{
    screen->win_mode = (sfVideoMode){1920, 1080, 32};
    screen->win = sfRenderWindow_create(screen->win_mode, "Wolf3d",
        sfFullscreen | sfClose, NULL);
    screen->menu = malloc(sizeof(menu_t) * NB_MENU);
    if (screen->menu == NULL)
        return false;
    if (!init_start_menu(&screen->menu[M_START], game_handler))
        return free(screen->menu), false;
    if (!init_pause_menu(&screen->menu[M_PAUSE], game_handler))
        return free(screen->menu), false;
    if (!init_settings_menu(&screen->menu[M_SETTING], game_handler))
        return free(screen->menu), false;
    if (!init_end_menu(&screen->menu[M_END], game_handler))
        return free(screen->menu), false;
    return true;
}

static
void init_settings(setting_t *settings)
{
    settings->music_volume = 50.0;
    settings->sound_volume = 50.0;
    settings->win_mode = WINM_FSCREEN;
    settings->win_size[0] = {(sfVector2f){1920, 1080}, (sfVector2f){800, 600}}
}

bool init_texture(tab_texture_t *textures)
{

}

int init_game_handler(game_handler_t *game_handler)
{
    sfTexture *wall = sfTexture_createFromFile("wall.bmp", NULL);

    game_handler->screen_mode = S_START;
    game_handler->game = NULL;
    if (!init_texture(game_handler->texture))
        return 84;
    if (!init_screen(&game_handler->screen, game_handler))
        return 84;
    if (init_binary_tree(&game_handler->buffer_z))
        return 84;
    init_controller(&game_handler->controller);
    init_setting(&game_handler->settings);
    if (game_handler->general_clock.clock == NULL
        || game_handler->window == NULL)
        return 84;
    return 0;
}

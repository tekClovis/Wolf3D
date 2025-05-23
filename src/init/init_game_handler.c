/*
** EPITECH PROJECT, 2025
** G-ING-210-REN-2-1-wolf3d-clovis.nedelec
** File description:
** init_game_handler
*/
#include "game.h"
#include "init.h"
#include "ray_casting.h"

void init_controller(controller_t *controller)
{
    controller->control = 0;
    controller->time = init_clock();
}

sfMusic *init_music(char *file, game_handler_t *g_h)
{
    sfMusic *music = sfMusic_createFromFile(file);

    sfMusic_play(music);
    sfMusic_setLoop(music, sfTrue);
    sfMusic_setVolume(music, g_h->settings.music_volume);
    return music;
}

static
screen_t *init_screen(game_handler_t *game_handler)
{
    screen_t *screen = malloc(sizeof(screen_t));

    screen->win_mode = (sfVideoMode){1920, 1080, 32};
    screen->win = sfRenderWindow_create(screen->win_mode, "Wolf3d",
        sfFullscreen | sfClose, NULL);
    screen->menu = malloc(sizeof(menu_t) * NB_MENU);
    screen->act_menu = M_START;
    if (screen->menu == NULL)
        return NULL;
    if (!init_start_menu(&screen->menu[M_START], game_handler))
        return free(screen->menu), NULL;
    if (!init_pause_menu(&screen->menu[M_PAUSE], game_handler))
        return free(screen->menu), NULL;
    if (!init_settings_menu(&screen->menu[M_SETTING], game_handler))
        return free(screen->menu), NULL;
    if (!init_end_menu(&screen->menu[M_END], game_handler))
        return free(screen->menu), NULL;
    screen->menu_music = init_music("sound/menu_music.mp3", game_handler);
    return screen;
}

static
void init_settings(setting_t *settings)
{
    settings->music_volume = 50.0;
    settings->sound_volume = 50.0;
    settings->win_mode = WINM_FSCREEN;
}

int init_game_handler(game_handler_t *game_handler)
{
    init_controller(&game_handler->controller);
    init_settings(&game_handler->settings);
    game_handler->screen_mode = S_MENU;
    game_handler->game = NULL;
    game_handler->texture = init_textures();
    game_handler->sound = init_sound();
    game_handler->screen = init_screen(game_handler);
    if (!game_handler->sound || !game_handler->texture ||
        !game_handler->screen)
        return 84;
    game_handler->general_clock = init_clock();
    if (game_handler->general_clock.clock == NULL)
        return 84;
    return 0;
}

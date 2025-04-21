/*
** EPITECH PROJECT, 2025
** minishell
** File description:
** my
*/


#ifndef GAME_H
    #define GAME_H
    #include "entities.h"
    #include "call_csfml.h"
    #include <stdbool.h>
    #define FPS_SET_60 16.666
    #define MOVEMENT_SPEED_2D_MAP 400
    #define M_PI 3.14159265358979323846
    #define DEG_TO_RAD(angle) ((angle) * (M_PI / 180.0))
int wolf3d(void);
/*
** Entitie handler
** contient toute les
** entité
*/
typedef struct entities_handler_s {
    player_t player;
    object_handler_t object;
    ennemies_t ennemies;
}entities_handler_t;


typedef struct time_management_s {
    sfClock *clock;
    sfTime time;
    sfInt64 time_as_micro_second;
    float time_as_second;
}time_management_t;

typedef struct class_map_s {
    entities_class_t map_player;
    entities_class_t map_wall;
    time_management_t frame_rate_clock;
}class_map_t;

typedef struct game_handler_s {
    sfEvent event;
    time_management_t general_clock;
    entities_handler_t entities;
    class_map_t map_2d;
    sfRenderWindow *window;
    int window_mode;
    sfTexture *wall;
}game_handler_t;

typedef struct game_mode_s {
    int (*funct)(game_handler_t *);
} game_mode_t;

int launch_game(game_handler_t *game_handler);

/*Game mode*/
int choose_window_mode(game_handler_t *game_handler);
int display_full_map(game_handler_t *game_handler);

/*Player*/
int move_player(game_handler_t *game_handler);
int rotate_player(game_handler_t *game_handler);

/*3D*/
float get_coord_wall(game_handler_t *game_handler, float angle, int precision);
int display_3d_map(game_handler_t *game_handler);

/*get*/
sfVector2f get_coord(sfVector2f coord_window);
bool is_in_real_wall(sfVector2f coord);
#endif //GAME_H

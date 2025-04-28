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
    #include "ray_casting.h"
    #include "controller.h"
    #include <stdbool.h>
    #include <math.h>
    #define WINDOW_SIZE_X 1980
    #define WINDOW_SIZE_y 1080
    #define FPS_SET_60 16.666
    #define WALK 100
    #define RUN 200
    #define M_PI 3.14159265358979323846
    #define RAY_SCREEN (1980.0f / 1440.0f)
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
    list_t *ennemies;
}entities_handler_t;

typedef struct game_handler_s {
    sfEvent event;
    time_management_t general_clock;
    entities_handler_t entities;
    sfRenderWindow *window;
    int window_mode;
    sfTexture *wall;
    sfRectangleShape *square;
    buffer_z_t *buffer_z;
    controller_t controller;
}game_handler_t;

typedef struct game_mode_s {
    int (*funct)(game_handler_t *);
} game_mode_t;

int launch_game(game_handler_t *game_handler);

/*Game mode*/
int choose_window_mode(game_handler_t *game_handler);
int display_full_map(game_handler_t *game_handler);

/*Player*/
void move_player(entities_class_t *entities);
void rotate_player(entities_class_t *entities);
void manage_player(game_handler_t *game_handler);

/*3D*/
float get_coord_wall(entities_class_t *entities, float angle, int precision);
int display_3d_map(game_handler_t *game_handler);
void free_game(game_handler_t *game_handler);

/*get*/
sfVector2f get_coord(sfVector2f coord_window);
bool is_in_real_wall(sfVector2f coord);

/*Controller*/
bool check_l3(void);
bool check_l2(void);
bool check_l1(void);
sfUint8 get_left_stick(void);

bool check_r3(void);
bool check_r2(void);
bool check_r1(void);
sfUint8 get_right_stick(void);

/*Time and clock*/
bool need_refresh_clock(time_management_t *sound_clock, float sec_reset);

#endif //GAME_H

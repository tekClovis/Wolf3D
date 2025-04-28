/*
** EPITECH PROJECT, 2025
** G-ING-210-REN-2-1-wolf3d-clovis.nedelec
** File description:
** display_3d_map
*/
#include "game.h"

static
void display_floor(sfRenderWindow *window, sfRectangleShape *square)
{
    sfColor my_color = {69, 200, 69, 255};

    sfRectangleShape_setTexture(square, NULL, sfTrue);
    sfRectangleShape_setSize(square, (sfVector2f){1980, 1082 / 2});
    sfRectangleShape_setPosition(square, (sfVector2f){0, 1080 / 2});
    sfRectangleShape_setFillColor(square, my_color);
    sfRenderWindow_drawRectangleShape(window, square, NULL);
    sfRectangleShape_setFillColor(square, (sfColor){100, 100, 100, 255});
}

/*
**Permet d afficher de la lumière a l aide
**D' un ray casting
*/
sfColor get_shadow(double distance)
{
    double shade = distance / CLOSE_DIST;
    sfColor color;

    shade *= 15;
    if (shade > 1)
        shade = 1;
    if (shade < 0.25)
        shade = 0.25;
    color = (sfColor){
        .r = (sfUint8)(255.0f * shade),
        .g = (sfUint8)(255.0f * shade),
        .b = (sfUint8)(255.0f * shade),
        .a = 255};
    return color;
}

/*
**Parse la variable buffer_z
**Pour afficher le bon rayon
**Puis applique l' ombre
*/
static
void draw_buffer_z(buffer_z_t *buffer, sfRectangleShape *square,
    sfTexture *wall, sfRenderWindow *window)
{
    sfRectangleShape_setSize(square, (sfVector2f)
    {1980 / 180, buffer->distance});
    sfRectangleShape_setPosition(square, (sfVector2f){(1980 / 90) *
        (buffer->id + 45.f), 1080 / 2 - (buffer->distance / 2)});
    sfRectangleShape_setTexture(square, wall, sfFalse);
    if (sfMouse_isButtonPressed(sfTrue) || check_l2() == true)
        sfRectangleShape_setFillColor(square, get_shadow(buffer->distance));
    else
        sfRectangleShape_setFillColor(square, (sfColor)
        {63.75, 63.75, 63.75, 255});
    //AFFICHE OMBRE
    sfRenderWindow_drawRectangleShape(window, square, NULL);
}

static
void fill_buffer_z(buffer_z_t *buffer_z, entities_class_t *entities,
    double i, double count)
{
    int element = (int)(count * 4.f);

    buffer_z[element].distance = 1000 / (get_coord_wall(entities, i, 90)
        * cos(DEG_TO_RAD(i)));
    buffer_z[element].type = 0;
    buffer_z[element].id = i;
}

void draw_ray_casting(game_handler_t *game_handler, sfRectangleShape *square)
{
    double count = 0;
    int element = 0;

    for (double i = -45; i < 45; i += 0.25){
        fill_buffer_z(game_handler->buffer_z,
            &game_handler->entities.player.property, i, count);
        count += 0.25;
        element++;
    }
    count = 0;
    element = 0;
    for (double i = -45; i < 45; i += 0.25){
        draw_buffer_z(&game_handler->buffer_z[element], square,
            game_handler->wall, game_handler->window);
        count += 0.25;
        element++;
    }
}

int display_3d_map(game_handler_t *game_handler)
{
    sfColor color = {69, 69, 69, 0};

    sfRenderWindow_clear(game_handler->window, color);
    display_floor(game_handler->window, game_handler->square);
    draw_ray_casting(game_handler, game_handler->square);
    move_player(&game_handler->entities.player.property);
    rotate_player(&game_handler->entities.player.property);
    return 0;
}

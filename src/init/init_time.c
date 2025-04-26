/*
** EPITECH PROJECT, 2025
** G-ING-210-REN-2-1-wolf3d-clovis.nedelec
** File description:
** init_player_ennemies
*/
#include "game.h"
#include "entities.h"

time_management_t init_clock(void)
{
    time_management_t time = {
        .clock = sfClock_create(),
        .time = {0},
        .time_as_micro_second = 0,
        .time_as_second = 0};

    return time;
}

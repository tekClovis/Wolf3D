/*
** EPITECH PROJECT, 2025
** minishell
** File description:
** my
*/

#ifndef TIME_H
    #define TIME_H
    #include "time.h"

typedef struct time_management_s {
    sfClock *clock;
    sfTime time;
    sfInt32 time_as_milli_sc;
    sfInt64 time_as_micro_second;
    float time_as_second;
}time_management_t;

#endif //TIME_H

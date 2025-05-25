/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** load_file
*/

#include "game.h"

bool load_from_file(game_handler_t *g_h, char *file, void *to_rd, ssize_t sz)
{
    FILE *fd = NULL;
    char path[256];

    snprintf(path, sizeof(path), "%s%s", g_h->game->actual_save, file);
    fd = fopen(path, "rb");
    if (fd == NULL)
        return false;
    fread(to_rd, sz, 1, fd);
    fclose(fd);
    return true;
}

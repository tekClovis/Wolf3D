/*
** EPITECH PROJECT, 2025
** G-ING-210-REN-2-1-wolf3d-clovis.nedelec
** File description:
** free_screen
*/

#include "game.h"

void free_list(node_t *node)
{
    node_t *tmp = NULL;

    if (node == NULL)
        return;
    tmp = node->next;
    free(node);
    return free_list(tmp);
}

void free_menu(menu_t *menu)
{
    menu->boutons->head->prev = NULL;
    menu->boutons->tail->next = NULL;
    free_list(menu->boutons->head);
    free(menu->boutons);
}

void free_screen(screen_t *screen)
{
    sfRenderWindow_destroy(screen->win);
    for (int i = 0; i != NB_MENU; i++){
        free_menu(&screen->menu[i]);
    }
    free(screen->menu);
}
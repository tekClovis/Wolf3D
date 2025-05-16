/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** init_textures
*/
#include "game.h"
#include "init.h"
#include "call_csfml.h"

const tab_texture_t tab_textures[] = {
    {NULL, T_BRUT, "./img/ent/Brut.png"},
    {NULL, T_MUTANT, "./img/ent/Mutant.png"},
    {NULL, T_SS, "./img/ent/SS_ennemies.png"},
    {NULL, T_M_BG, "./img/menu/menu_bg.png"},
    {NULL, T_M2D, "./img/mode_2D.png"},
    {NULL, T_M3D, "./img/mode_3D.png"},
    {NULL, T_P_2D, "./img/player_2d.png"},
    {NULL, 0, NULL}
};

const size_tab_textures = sizeof(tab_textures) / sizeof(*tab_textures);

bool init_textures(tab_texture_t *textures)
{
    textures = malloc(sizeof(tab_texture_t) * size_tab_textures);

    if (textures == NULL)
        return false;
    for (int i = 0; i < size_tab_textures; i++){
        textures[i] = tab_textures[i];
        textures[i].texture = sfFont_createFromFile(textures[i].file);
    }
    return true;
}

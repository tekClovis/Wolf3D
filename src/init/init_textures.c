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
    {NULL, T_B_S1, "./img/menu/s1_bouton.png"},
    {NULL, T_B_S2, "./img/menu/s2_bouton.png"},
    {NULL, T_B_S3, "./img/menu/s3_bouton.png"},
    {NULL, T_B_EXIT, "./img/menu/exit.png"},
    {NULL, T_B_SETTINGS, "./img/menu/settings.png"},
    {NULL, T_ARR_L, "./img/menu/arrow_l.png"},
    {NULL, T_ARR_R, "./img/menu/arrow_r.png"},
    {NULL, T_B_HOME, "img/menu/home_bouton.png"},
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

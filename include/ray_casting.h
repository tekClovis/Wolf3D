/*
** EPITECH PROJECT, 2025
** minishell
** File description:
** my
*/


#ifndef RAY_CASTING_H
    #define RAY_CASTING_H
    #include <stddef.h>

/*
** ID CORRESPOND A LA TEXTURE A AFFICHER
** Next_node est un size_t qui correspond a un mur plus loins
** Prev_node correspond a un mur plus proche
*/
typedef struct buffer_s {
    size_t id;
    size_t next_node;
    size_t prev_node;
}buffer_t;

/*
** Node contient tous l arbre binaire
** qui contient lui meme tous ce
** qu' il faut afficher
*/
typedef struct ray_casting_s {
    buffer_t *node;
    double *z_buffer;
}ray_casting_t;

#endif //RAY_CASTING_H

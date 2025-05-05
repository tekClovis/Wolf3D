/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** handle_ent_event
*/
#include "game.h"
#include "entities.h"

const angle_sprite_t SPRITE_TAB[] = {
    {{337.5, 22.5}, 0},
    {{22.5, 67.5}, 1},
    {{67.5, 112.5}, 2},
    {{112.5, 157.5}, 3},
    {{157.5, 202.5}, 4},
    {{202.5, 247.5}, 5},
    {{247.5, 292.5}, 6},
    {{292.5, 337.5}, 7}
};


static
void aim_player(player_t *player, ennemies_t *ennemies)
{
    ennemies->property.angle = fmodf(player->angle + 180.0, 360.0);
}

float get_relative_angle(entities_class_t player, entities_class_t ennemies)
{
    sfVector2f position_v = {player.coord.x - ennemies.coord.x,
        player.coord.y - ennemies.coord.y};
    double rad_angle = ennemies.angle * (M_PI / 180.0);
    sfVector2f angle_v = {cos(rad_angle), sin(rad_angle)};
    float scalaire = angle_v.x * position_v.x + angle_v.y * position_v.y;
    float magA = sqrt(position_v.x * position_v.x +
        position_v.y * position_v.y);
    float magB = sqrt(angle_v.x * angle_v.x +
        angle_v.y * angle_v.y);
    float finalRadians = (scalaire / (magA * magB));

    return finalRadians * (180.0 / M_PI);
}

void rotate_sprite(player_t *player, ennemies_t *ennemi)
{
    sfIntRect new_rect;
    float angle;

    if (ennemi->property.id == BRUT)
        return;
    new_rect = sfSprite_getTextureRect(ennemi->property.sprite);
    angle = get_relative_angle(player->property, ennemi->property);
    if (angle > SPRITE_TAB[0].angle_interval.x ||
    angle < SPRITE_TAB[0].angle_interval.x)
        new_rect.left = 0;
    for (int i = 1; i < 8; i++)
        if (angle > SPRITE_TAB[i].angle_interval.x &&
            angle < SPRITE_TAB[i].angle_interval.x)
            new_rect.left = 65 * SPRITE_TAB[i].sprite_coef;
    sfSprite_setTextureRect(ennemi->property.sprite, new_rect);
}

//actual node set at the second node because the first is the player
void handle_ent_event(struct game_handler_s *game_handler)
{
    node_t *actual = game_handler->entities.ennemies->head->next;
    player_t *player = &game_handler->entities.player;

    for (; actual; actual = actual->next){
        if (((ennemies_t *)actual->data)->property.life < 0)
            continue;
        detect_player(actual->data, player);
        if (((ennemies_t *)actual->data)->can_shoot
            && ((ennemies_t *)actual->data)->hit_clock.time_as_micro_second){
            aim_player(player, actual->data);
            ((ennemies_t *)actual->data)->gun_shot(player, actual->data);
            continue;
        }
        move_ennemies(actual->data);
        rotate_sprite(player, actual->data);
    }
}

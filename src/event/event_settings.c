/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** event_settings
*/

#include "game.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <SFML/Audio/Music.h>
#include "functions.h"

void e_s3(game_t *game, sfEvent event, sfVector2i pos)
{
    if (1312 < pos.x && pos.x < 1762 && 330 < pos.y && pos.y < 430) {
        (*game->b_anim[0])(game, game->buttons[10], 0, 450);
        if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue) {
            (*game->b_anim[1])(game, game->buttons[10], 2, 900);
            game->buttons[14]->rect.left = 0;
            sfSprite_setTextureRect(game->buttons[14]->sprite,
            game->buttons[14]->rect);
            game->high_or_low = 1;
        }
    }
    if (1312 < pos.x && pos.x < 1762 && 643 < pos.y && pos.y < 743) {
        (*game->b_anim[0])(game, game->buttons[11], 0, 450);
        if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue) {
            (*game->b_anim[1])(game, game->buttons[11], 2, 900);
            game->buttons[14]->rect.left = 125;
            sfSprite_setTextureRect(game->buttons[14]->sprite,
            game->buttons[14]->rect);
            game->high_or_low = 0;
        }
    }
}

void e_s2(game_t *game, sfEvent event, sfVector2i pos)
{
    if (159 < pos.x && pos.x < 609 && 644 < pos.y && pos.y < 744) {
        (*game->b_anim[0])(game, game->buttons[9], 0, 450);
        if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue) {
            (*game->b_anim[1])(game, game->buttons[9], 2, 900);
            game->buttons[13]->rect.left = 125;
            sfSprite_setTextureRect(game->buttons[13]->sprite,
            game->buttons[13]->rect);
            sfMusic_setVolume(game->music->menu, 0);
            sfMusic_setVolume(game->music->game, 0);
        }
    }
}

void e_s1(game_t *game, sfEvent event, sfVector2i pos)
{
    if (159 < pos.x && pos.x < 609 && 330 < pos.y && pos.y < 430) {
        (*game->b_anim[0])(game, game->buttons[8], 0, 450);
        if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue) {
            (*game->b_anim[1])(game, game->buttons[8], 2, 900);
            game->buttons[13]->rect.left = 0;
            sfSprite_setTextureRect(game->buttons[13]->sprite,
            game->buttons[13]->rect);
            sfMusic_setVolume(game->music->menu, 10);
            sfMusic_setVolume(game->music->game, 20);
        }
    }
}

void e_settings(game_t *game, sfEvent event, sfVector2i pos)
{
    e_s1(game, event, pos);
    e_s2(game, event, pos);
    e_s3(game, event, pos);
    if (736 < pos.x && pos.x < 1186 && 893 < pos.y && pos.y < 993) {
        (*game->b_anim[0])(game, game->buttons[12], 0, 450);
        if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue)
            (*game->b_anim[1])(game, game->buttons[12], 0, 900);
    }
}
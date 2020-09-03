/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** settings
*/

#include "game.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>
#include "functions.h"

void settings(game_t *game)
{
    for (int i = 8; i < 13; i++) {
        game->buttons[i]->rect.left = 0;
        sfSprite_setTextureRect(game->buttons[i]->sprite,
        game->buttons[i]->rect);
    }
    sfSprite_setTexture(game->window->backg, game->window->t_settings, sfTrue);
    sfRenderWindow_drawSprite(game->window->w, game->window->backg, NULL);
    for (int i = 8; i < 15; i++)
        sfRenderWindow_drawSprite(game->window->w, game->buttons[i]->sprite,
        NULL);
}
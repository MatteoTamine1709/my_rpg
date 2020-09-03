/*
** EPITECH PROJECT, 2024
** MUL_my_rpg_2019
** File description:
** MUL_my_rpg_2019
*/

#include "game.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>
#include "functions.h"

void tbc(game_t *game)
{
    game->buttons[8]->rect.left = 0;
    sfSprite_setTextureRect(game->buttons[7]->sprite, game->buttons[7]->rect);
    sfSprite_setTexture(game->window->backg, game->window->t_tbc, sfTrue);
    sfRenderWindow_drawSprite(game->window->w, game->window->backg, NULL);
    sfRenderWindow_drawSprite(game->window->w, game->buttons[7]->sprite, NULL);
}
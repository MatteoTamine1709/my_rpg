/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** help
*/

#include "game.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>
#include "functions.h"

void help(game_t *game)
{
    game->buttons[8]->rect.left = 0;
    sfSprite_setTextureRect(game->buttons[12]->sprite, game->buttons[12]->rect);
    sfSprite_setTexture(game->window->backg, game->window->t_help, sfTrue);
    sfRenderWindow_drawSprite(game->window->w, game->window->backg, NULL);
    sfRenderWindow_drawSprite(game->window->w, game->buttons[12]->sprite, NULL);
}
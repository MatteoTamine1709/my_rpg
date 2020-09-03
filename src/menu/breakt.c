/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** breakt
*/

#include "game.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>
#include "functions.h"

void breakt(game_t *game)
{
    for (int i = 5; i < 8; i++) {
        game->buttons[i]->rect.left = 0;
        sfSprite_setTextureRect(game->buttons[i]->sprite,
        game->buttons[i]->rect);
    }
    sfSprite_setTexture(game->window->backg, game->window->t_bt, sfTrue);
    sfRenderWindow_drawSprite(game->window->w, game->window->backg, NULL);
    for (int i = 5; i < 8; i++)
        sfRenderWindow_drawSprite(game->window->w, game->buttons[i]->sprite,
        NULL);
}
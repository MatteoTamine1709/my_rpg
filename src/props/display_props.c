/*
** EPITECH PROJECT, 2020
** test
** File description:
** main
*/

#include "game.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "functions.h"
#include "my.h"

void display_props(prop_t *props, game_t *game)
{
    for (int i = 0; i < game->nb_props; i++) {
        sfRenderWindow_drawSprite(game->window->w, props[i].sprite, NULL);
    }
}
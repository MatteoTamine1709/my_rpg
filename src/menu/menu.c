/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** menu
*/

#include "game.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>
#include <SFML/Audio/Music.h>
#include "functions.h"

void menu(game_t *game)
{
    if (game->w_music % 2 == 0) {
            sfMusic_play(game->music->menu);
            game->w_music++;
    }
    for (int i = 0; i < 5; i++) {
        game->buttons[i]->rect.left = 0;
        sfSprite_setTextureRect(game->buttons[i]->sprite,
        game->buttons[i]->rect);
    }
    sfSprite_setTexture(game->window->backg, game->window->t_menu, sfTrue);
    sfRenderWindow_drawSprite(game->window->w, game->window->backg, NULL);
    for (int i = 0; i < 5; i++)
        sfRenderWindow_drawSprite(game->window->w, game->buttons[i]->sprite,
        NULL);
}
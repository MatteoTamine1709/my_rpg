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

void e_help(game_t *game, sfEvent event, sfVector2i pos)
{
    if (736 < pos.x && pos.x < 1186 && 893 < pos.y && pos.y < 993) {
        (*game->b_anim[0])(game, game->buttons[12], 0, 450);
        if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue)
            (*game->b_anim[1])(game, game->buttons[12], 0, 900);
    }
}

void e_load(game_t *game, sfEvent event, sfVector2i pos)
{
    return;
}

void e_quit(game_t *game, sfEvent event, sfVector2i pos)
{
    return;
}
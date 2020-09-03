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

void shot_fight(game_t *game, sfEvent event)
{
    if (event.type == sfEvtKeyPressed && sfKeyboard_isKeyPressed(sfKeyA)) {
        game->battle->attack_type = 0;
        player_shot(game->battle, game);
    }
    if (event.type == sfEvtKeyPressed && sfKeyboard_isKeyPressed(sfKeyZ)) {
        game->battle->attack_type = 1;
        player_shot(game->battle, game);
    }
    if (event.type == sfEvtKeyPressed && sfKeyboard_isKeyPressed(sfKeyE)) {
        game->battle->attack_type = 2;
        player_shot(game->battle, game);
    }
}

void event_fight(game_t *game, sfEvent event)
{
    if (event.type == sfEvtKeyPressed && sfKeyboard_isKeyPressed(sfKeyQ))
        game->battle->dodge = 0;
    if (event.type == sfEvtKeyPressed && sfKeyboard_isKeyPressed(sfKeyS))
        game->battle->dodge = 1;
    if (event.type == sfEvtKeyPressed && sfKeyboard_isKeyPressed(sfKeyD))
        game->battle->dodge = 2;
    if (game->battle->shot == 1)
        return;
    shot_fight(game, event);
}
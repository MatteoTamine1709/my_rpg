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
#include <math.h>
#include "functions.h"
#include "my.h"

game_t *redirect(redirect_t redirect, player_t *player, game_t *game)
{
    player->dir.x = 0;
    player->dir.y = 0;
    player->pos = redirect.dest_pos;
    player->destination_point.x = player->pos.x;
    player->destination_point.y = player->pos.y;
    game->player->size = redirect.dest_size;
    sfSprite_setScale(game->player->sprite, redirect.dest_size);
    game->current_map = redirect.redirect_name;
    game = redirect_border(game->player, game);
    return (game);
}

int check_redirect(game_t *game, player_t *player)
{
    for (int i = 0; i < game->nb_redirect; i++) {
        if (abs(player->pos.x - (game->redirects[i].pos.x + 30)) <
        game->redirects[i].hitbox_size.x &&
        abs(player->pos.y - (game->redirects[i].pos.y + 30)) <
        game->redirects[i].hitbox_size.y) {
            player->pos.x -= player->dir.x;
            player->pos.y -= player->dir.y;
            game = redirect(game->redirects[i], player, game);
            return (1);
        }
    }
    return (0);
}
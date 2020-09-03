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

game_t *redirect_border(player_t *player, game_t *game)
{
    player->dir.x = 0;
    player->dir.y = 0;
    player->destination_point.x = player->pos.x;
    player->destination_point.y = player->pos.y;
    game->redirects = move_redirect("saves/save1/redirection/", game);
    game->npcs = move_npc("saves/save1/npc/", game);
    game->props = move_props("saves/save1/props/", game);
    game->lights = move_light("saves/save1/light/", game);
    game->effect_index = move_effect("saves/save1/effect/", game);
    game->fg_map = move("saves/save1/foreground/", game);
    game->mg_map = move("saves/save1/middleground/", game);
    game->bg_map = move("saves/save1/background/", game);
    return (game);
}

int map_border(player_t *player)
{
    if (player->pos.y < 0 + 30 + 10 && player->dir.y < 0) {
        player->pos.y = 1080 - 30 - 10;
        return (1);
    }
    if (player->pos.x > 1920 - 30 - 10 && player->dir.x > 0) {
        player->pos.x = 30 + 10;
        return (2);
    }
    if (player->pos.y > 1080 - 30 - 10 && player->dir.y > 0) {
        player->pos.y = 30 + 10;
        return (3);
    }
    if (player->pos.x < 0 + 30 + 10 && player->dir.x < 0) {
        player->pos.x = 1920 - 30 - 10;
        return (4);
    }
    return (0);
}

game_t *check_map_border(player_t *player, game_t *game)
{
    int border = map_border(player);

    if (border == 1)
        game->current_map = game->bg_map->top;
    if (border == 2)
        game->current_map = game->bg_map->right;
    if (border == 3)
        game->current_map = game->bg_map->bot;
    if (border == 4)
        game->current_map = game->bg_map->left;
    if (border) {
        game = redirect_border(player, game);
    }
    return (game);
}
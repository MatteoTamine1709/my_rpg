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

int npc_collision(game_t *game, player_t *player, int i)
{
    if (abs(player->pos.x - (game->npcs[i].pos.x +
    game->npcs[i].hitbox_size.x)) < game->npcs[i].hitbox_size.x &&
    abs((player->pos.y + 30) - (game->npcs[i].pos.y +
    game->npcs[i].hitbox_size.y)) < game->npcs[i].hitbox_size.y &&
    (game->npcs[i].stat == NULL || game->npcs[i].stat->hp > 0)) {
        player->npc_interact_index = i;
        if (player->stuck == 0)
            game->npcs[i].start_dialog = 1;
        npc_shop(game, player, i);
        npc_enemy(game, player, i);
        player = check_quest(player, game, i);
        if (player->stuck == 0 && (game->npcs[i].type == 3 ||
        game->npcs[i].type == 2) && game->player->has_quest == 0)
            game = get_quest(game, i);
        player->pos.x -= player->dir.x;
        player->pos.y -= player->dir.y;
        return (1);
    } else
        npc_end_action(game, player, i);
    return (0);
}

int check_npc(game_t *game, player_t *player)
{
    for (int i = 0; i < game->nb_npc; i++)
        if (npc_collision(game, player, i))
            return (1);
    return (0);
}

int check_props(game_t *game, player_t *player)
{
    for (int i = 0; i < game->nb_props; i++)
        if (abs(player->pos.x - (game->props[i].pos.x + 30)) <
        game->props[i].hitbox_size.x &&
        abs(player->pos.y - (game->props[i].pos.y + 30)) <
        game->props[i].hitbox_size.y) {
            player->pos.x -= player->dir.x;
            player->pos.y -= player->dir.y;
            return (1);
        }
    return (0);
}

void update_player_pos(player_t *player, float dist_f, game_t *game)
{
    int collision = 0;
    player->dir.x = ((player->destination_point.x - player->pos.x) / dist_f) *
    player->walk_speed;
    player->dir.y = ((player->destination_point.y - player->pos.y) / dist_f) *
    player->walk_speed;
    player->pos.x += player->dir.x;
    player->pos.y += player->dir.y;
    game = check_map_border(player, game);
    if (hitbox_bg(game, player) || hitbox_mg(game, player) ||
    hitbox_fg(game, player) || check_npc(game, player) ||
    check_props(game, player) || check_redirect(game, player))
        player->destination_point = player->pos;
}

void update_player(player_t *player, game_t *game)
{
    float dist_f = dist(player->pos.x, player->pos.y,
        player->destination_point.x, player->destination_point.y);

    if (dist_f <= player->walk_speed) {
        player->pos.x = player->destination_point.x;
        player->pos.y = player->destination_point.y;
        player->dir.x = 0;
        player->dir.y = 0;
        return;
    }
    update_player_pos(player, dist_f, game);
}
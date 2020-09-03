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

game_t *get_quest(game_t *game, int index)
{
    for (int i = 0; i < game->nb_quest; i++) {
        if (my_strcmp(game->quests[i].map_npc_talk, game->current_map) == 0 &&
            index == game->quests[i].index_npc_talk) {
            game->player->quest = game->quests[i];
            game->player->has_quest = 1;
        }
    }
    return (game);
}

player_t *check_quest(player_t *player, game_t *game, int index)
{
    if (my_strcmp(player->quest.map_npc_receiver, game->current_map) == 0 &&
        index == player->quest.index_npc_receiver) {
        game->player->numberquests += 1;
        player->has_quest = 0;
    }
    return (player);
}

void npc_enemy(game_t *game, player_t *player, int i)
{
    if (player->stuck == 0 && game->npcs[i].type == 2 &&
        player->in_fight == 0 && game->npcs[i].render_state == 1 &&
        player->stat->hp > 0) {
        save_npc(game);
        game->player->npc_interact_index = game->nb_npc - 1;
        game->battle = set_battle(game->battle, player, &game->npcs[i]);
        if (game->battle != NULL)
            player->in_fight = 1;
    }
}

void npc_shop(game_t *game, player_t *player, int i)
{
    if (player->stuck == 0 && game->npcs[i].type == 1 &&
        player->inventory_open == 0 && player->in_shop == 0) {
        player->in_shop = 1;
        player->inventory_open = 1;
        player->stuck = 1;
        player->inventory = set_inventory_shop(player->inventory, -1, game);
    }
}

void npc_end_action(game_t *game, player_t *player, int i)
{
    if (player->in_shop == 1) {
        player->inventory = set_inventory_shop(player->inventory, 1, game);
        player->in_shop = 0;
    } else if (player->in_fight == 1)
        player->in_fight = 0;
}
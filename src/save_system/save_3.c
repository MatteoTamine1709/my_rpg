/*
** EPITECH PROJECT, 2024
** MUL_my_rpg_2019
** File description:
** MUL_my_rpg_2019
*/

#include "game.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>
#include <errno.h>
#include "my.h"
#include "functions.h"

void save_npc_stat_two(char *rewrite, game_t *game, int *i, int diff)
{
    save_itoa_dot(rewrite,
        (int)game->npcs[game->player->npc_interact_index].stat->speed, i, diff);
    save_itoa_dot(rewrite,
        (int)game->npcs[game->player->npc_interact_index].stat->dodge, i, diff);
    save_itoa_dot(rewrite,
        (int)game->npcs[game->player->npc_interact_index].stat->crit, i, diff);
    save_itoa_dot(rewrite,
        (int)game->npcs[game->player->npc_interact_index].stat->stamina, i,
        diff);
    save_itoa_dot(rewrite, (int)game->npcs
    [game->player->npc_interact_index].stat->regen_stamina, i, diff);
    save_itoa_dot(rewrite, (int)game->npcs
    [game->player->npc_interact_index].stat->dodge_accurancy, i, diff);
}

void save_npc_stat(char *rewrite, game_t *game, int *i, int diff)
{
    if (game->npcs[game->player->npc_interact_index].stat != NULL) {
        save_itoa_dot(rewrite, (int)game->npcs
        [game->player->npc_interact_index].stat->level, i, diff);
        save_itoa_dot(rewrite,
            (int)game->npcs[game->player->npc_interact_index].stat->hp, i,
            diff);
        save_itoa_dot(rewrite, (int)game->npcs
        [game->player->npc_interact_index].stat->weapon_index, i, diff);
        save_itoa_dot(rewrite, (int)game->npcs
        [game->player->npc_interact_index].stat->chest_index, i, diff);
        save_itoa_dot(rewrite, (int)game->npcs
        [game->player->npc_interact_index].stat->leg_index, i, diff);
        save_npc_stat_two(rewrite, game, i, diff);
    }
    rewrite[(*i) - diff] = '\n';
    (*i)++;
}

void save_npc_i_w(char *rewrite, game_t *game, int *i, int diff)
{
    if (game->npcs[game->player->npc_interact_index].items != NULL)
        for (int j = 0; j < game->npcs
        [game->player->npc_interact_index].nb_items; j++) {
            save_itoa_dot(rewrite, (int)game->npcs
            [game->player->npc_interact_index].items[j], i, diff);
        }
    rewrite[(*i) - diff] = '\n';
    (*i)++;
    if (game->npcs[game->player->npc_interact_index].weapons != NULL)
        for (int j = 0; j < game->npcs
        [game->player->npc_interact_index].nb_weapons; j++) {
            save_itoa_dot(rewrite, (int)game->npcs
            [game->player->npc_interact_index].weapons[j], i, diff);
        }
    rewrite[(*i) - diff] = '\n';
    (*i)++;
}

void final_npc_write(char *rewrite, game_t *game, int i, int diff)
{
    int fd = open(my_strcat("saves/save1/npc/", game->current_map), O_RDWR |
        O_CREAT | O_TRUNC, 0644);
    write(fd, rewrite, sizeof(char) * (i - diff));
    close(fd);
}

void end_save_npc(char *rewrite, game_t *game, int *i, int diff)
{
    for (int j = 0; j < 4; j++, (*i)++)
        rewrite[(*i) - diff] = '/';
    rewrite[(*i) - diff] = '\0';
}
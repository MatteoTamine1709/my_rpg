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

void save_npc_walk(char *rewrite, game_t *game, int *i, int diff)
{
    if (game->npcs[game->player->npc_interact_index].movements != NULL)
        for (int j = 0; j < game->npcs
        [game->player->npc_interact_index].nb_movements; j++) {
            save_itoa_dot(rewrite, (int)game->npcs
            [game->player->npc_interact_index].movements[j].x, i, diff);
            save_itoa_dot(rewrite, (int)game->npcs
            [game->player->npc_interact_index].movements[j].y, i, diff);
        }
    rewrite[(*i) - diff] = '\n';
    (*i)++;
    save_itoa(rewrite,
        (int)game->npcs[game->player->npc_interact_index].walk_speed, i, diff);
}

void save_npc(game_t *game)
{
    int fd = open(my_strcat("saves/save1/npc/", game->current_map),
        O_RDONLY | O_CREAT, 0644);
    char buff[2000];
    char *rewrite;
    int size = read(fd, buff, sizeof(char) * 2000);
    int diff = 0;
    int i = 0;

    if (game->player->npc_interact_index == -1)
        return;
    buff[size] = '\0';
    rewrite = copy_all_npcs(game, buff, &i, &diff);
    save_npc_fix(rewrite, game, &i, diff);
    save_npc_walk(rewrite, game, &i, diff);
    save_npc_stat(rewrite, game, &i, diff);
    save_npc_i_w(rewrite, game, &i, diff);
    end_save_npc(rewrite, game, &i, diff);
    close(fd);
    final_npc_write(rewrite, game, i, diff);
}
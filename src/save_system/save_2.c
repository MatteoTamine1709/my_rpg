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

void save_itoa(char *rewrite, int val, int *i, int diff)
{
    char *val_c = my_itoa(val);

    for (int j = 0; j < my_strlen(val_c); j++, (*i)++)
        rewrite[(*i) - diff] = val_c[j];
    rewrite[(*i) - diff] = '\n';
    (*i)++;
}

void save_itoa_dot(char *rewrite, int val, int *i, int diff)
{
    char *val_c = my_itoa(val);

    for (int j = 0; j < my_strlen(val_c); j++, (*i)++)
        rewrite[(*i) - diff] = val_c[j];
    rewrite[(*i) - diff] = '.';
    (*i)++;
}

void save_char(char *rewrite, char *val, int *i, int diff)
{
    if (val != NULL)
        for (int j = 0; j < my_strlen(val); j++, (*i)++)
            rewrite[(*i) - diff] = val[j];
    rewrite[(*i) - diff] = '\n';
    (*i)++;
}

void save_npc_fix(char *rewrite, game_t *game, int *i, int diff)
{
    save_itoa(rewrite, (int)game->npcs[game->player->npc_interact_index].pos.x,
        i, diff);
    save_itoa(rewrite, (int)game->npcs[game->player->npc_interact_index].pos.y,
        i, diff);
    save_itoa(rewrite,
        (int)game->npcs[game->player->npc_interact_index].hitbox_size.x, i,
        diff);
    save_itoa(rewrite,
        (int)game->npcs[game->player->npc_interact_index].hitbox_size.y, i,
        diff);
    save_itoa(rewrite, (int)game->npcs[game->player->npc_interact_index].type,
        i, diff);
    save_itoa(rewrite,
        (int)game->npcs[game->player->npc_interact_index].frame_count, i, diff);
    save_char(rewrite, game->npcs[game->player->npc_interact_index].sound_path,
        i, diff);
    save_npx_fix_2(rewrite, game, i, diff);
}

void save_npx_fix_2(char *rewrite, game_t *game, int *i, int diff)
{
    save_char(rewrite,
        game->npcs[game->player->npc_interact_index].texture_path, i, diff);
    save_char(rewrite,
        game->npcs[game->player->npc_interact_index].texture_path_fight, i,
        diff);
    save_itoa(rewrite, game->npcs[game->player->npc_interact_index].text, i,
        diff);
}
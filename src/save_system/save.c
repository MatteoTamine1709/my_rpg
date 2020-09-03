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
#include <time.h>
#include <errno.h>
#include "my.h"
#include "functions.h"

void save_pos_size(game_t *game, int fd)
{
    char *pos_x = my_itoa_n((int)game->player->pos.x);
    char *pos_y = my_itoa_n((int)game->player->pos.y);
    char *size_x = my_itoa_n((int)game->player->size.x);
    char *size_y = my_itoa_n((int)game->player->size.y);

    write(fd, pos_x, my_strlen(pos_x));
    write(fd, pos_y, my_strlen(pos_y));
    write(fd, size_x, my_strlen(size_x));
    write(fd, size_y, my_strlen(size_y));
}

void save_stats_stam(game_t *game, int fd)
{
    char *stamina = my_itoa_n(game->player->stat->stamina);
    char *regen_stamina = my_itoa_n(game->player->stat->regen_stamina);

    write(fd, stamina, my_strlen(stamina));
    write(fd, regen_stamina, my_strlen(regen_stamina));
}

void save_stats(game_t *game, int fd)
{
    char *level = my_itoa_n(game->player->stat->level);
    char *hp = my_itoa_n(game->player->stat->hp);
    char *weapon_index = my_itoa_n(game->player->stat->weapon_index);
    char *chest_index = my_itoa_n(game->player->stat->chest_index);
    char *leg_index = my_itoa_n(game->player->stat->leg_index);
    char *speed = my_itoa_n(game->player->stat->speed);
    char *dodge = my_itoa_n(game->player->stat->dodge);
    char *crit = my_itoa_n(game->player->stat->crit);

    write(fd, level, my_strlen(level));
    write(fd, hp, my_strlen(hp));
    write(fd, weapon_index, my_strlen(weapon_index));
    write(fd, chest_index, my_strlen(chest_index));
    write(fd, leg_index, my_strlen(leg_index));
    write(fd, speed, my_strlen(speed));
    write(fd, dodge, my_strlen(dodge));
    write(fd, crit, my_strlen(crit));
    save_stats_stam(game, fd);
}

void save(game_t *game)
{
    int fd = open("saves/save1/player", O_RDWR | O_CREAT | O_TRUNC, 0644);

    save_pos_size(game, fd);
    save_stats(game, fd);
    for (int i = 0; i < 17; i++) {
        write(fd, my_itoa(game->player->inventory->item_num[i]),
        my_strlen(my_itoa(game->player->inventory->item_num[i])));
        write(fd, ".", my_strlen("."));
    }
    write(fd, "\n", my_strlen("\n"));
    for (int i = 0; i < 17; i++) {
        write(fd, my_itoa(game->player->inventory->weapon_num[i]),
        my_strlen(my_itoa(game->player->inventory->weapon_num[i])));
        write(fd, ".", my_strlen("."));
    }
    write(fd, "\n////", my_strlen("\n////"));
    close(fd);
    fd = open("saves/save1/current_map_load", O_RDWR | O_CREAT | O_TRUNC, 0644);
    write(fd, game->current_map, my_strlen(game->current_map));
    close(fd);
}

char *copy_all_npcs(game_t *game, char *buff, int *i, int *diff)
{
    int index = 0;
    char *rewrite = my_malloc(sizeof(char) * 2000);

    for (*i = 0; *i < get_size_n(buff, 0); (*i)++)
        rewrite[*i] = buff[*i];
    rewrite[*i] = '\n';
    for (*i; *i < my_strlen(buff); (*i)++) {
        if (index < game->player->npc_interact_index ||
            index > game->player->npc_interact_index)
            rewrite[(*i) - (*diff)] = buff[*i];
        else
            (*diff)++;
        if (buff[*i] == '/' && buff[(*i) + 1] == '\n')
            index++;
    }
    rewrite[(*i) - (*diff)] = '\n';
    (*i)++;
    return (rewrite);
}
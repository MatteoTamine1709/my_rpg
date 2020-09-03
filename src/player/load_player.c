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

int set_player_pos(player_t *player, char *buff)
{
    int i = 0;

    player->pos.x = my_atoi_n(buff, i);
    i += get_size_n(buff, i) + 1;
    player->pos.y = my_atoi_n(buff, i);
    i += get_size_n(buff, i) + 1;
    player->destination_point = player->pos;
    player->size.x = my_atoi_n(buff, i);
    i += get_size_n(buff, i) + 1;
    player->size.y = my_atoi_n(buff, i);
    i += get_size_n(buff, i) + 1;
    player->destination_point = player->pos;
    return (i);
}

void load_player_inventory(char *buff, int i, player_t *player)
{
    player->inventory->item_num = get_list(buff, &i, 0);
    i += get_size_n(buff, i) + 1;
    player->inventory->weapon_num = get_list(buff, &i, 0);
}

player_t *load_player_info(char *buff, int size, player_t *player)
{
    int index = 0;
    int i = 0;
    stat_t *(*set_player_var[])(stat_t *, int) = {player_stat_level,
    player_stat_hp, player_stat_weapon, player_stat_chest, player_stat_leg,
    player_stat_init, player_stat_dodge, player_stat_crit, player_stat_stamina,
    player_stat_regen};

    i = set_player_pos(player, buff);
    for (i; i < size;
        i += (get_size_n(buff, i) + 1)) {
        if (index < 10)
            player->stat = (*set_player_var[index])(player->stat,
            my_atoi_n(buff, i));
        index++;
        if (index == 11)
            break;
    }
    load_player_inventory(buff, i, player);
    return (player);
}

player_t *fill_player(player_t *player)
{
    player->pos = (sfVector2f) {-1, -1};
    player->destination_point = player->pos;
    player->dir = (sfVector2f) {0, 0};
    player->rect = (sfIntRect) {0, 0, 60, 60};
    player->stuck = 0;
    player->anim = 0;
    player->frame = 0;
    player->walk_speed = 5;
    player->npc_interact_index = -1;
    player->inventory_open = 0;
    player->in_shop = 0;
    player->in_fight = 0;
    player->size = (sfVector2f) {1, 1};
    player->stat = my_malloc(sizeof(stat_t));
    player->inventory = my_malloc(sizeof(inventory_t));
    return (player);
}

player_t *load_player(char *filepath, game_t *game)
{
    int fd = open(filepath, O_RDONLY);
    char buff[2000];
    int size;
    player_t *player;

    if (fd == -1)
        return NULL;
    size = read(fd, buff, sizeof(char) * 2000);
    if (size < 2)
        return (NULL);
    buff[size] = '\0';
    player = my_malloc(sizeof(player_t));
    player = fill_player(player);
    player = load_player_info(buff, size, player);
    player = set_player_design(player, game);
    return (player);
}
/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** set_npc_var2
*/

#include "game.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "functions.h"

sfVector2f *get_movements(char *buff, int *i)
{
    int nb_movements = 0;
    int j = 0;
    int index = 0;
    sfVector2f *movements;

    for (j = *i; buff[j] != '\n' && buff[j] != '\0'; j++)
        if (buff[j] == '.')
            nb_movements++;
    if (nb_movements % 2 == 1 || nb_movements == 0)
        return (NULL);
    movements = my_malloc(sizeof(sfVector2f) * ((nb_movements / 2)));
    for (j = 0; j < nb_movements; *i += get_size_dot(buff, *i) + 1, j++) {
        if (j % 2 == 0) {
            movements[index].x = my_atoi_dot(buff, *i);
        } else if (j % 2 == 1) {
            movements[index].y = my_atoi_dot(buff, *i);
            index++;
        }
    }
    return (movements);
}

int *get_list(char *buff, int *i, int size)
{
    int nb_list = 0;
    int j = 0;
    int *list;

    for (j = *i; buff[j] != '\n' && buff[j] != '\0'; j++)
        if (buff[j] == '.')
            nb_list++;
    if (nb_list == 0)
        return (NULL);
    list = my_malloc(sizeof(int) * (nb_list + 1));
    for (j = 0; j < nb_list; *i += get_size_dot(buff, *i) + 1, j++) {
        list[j] = my_atoi_dot(buff, *i);
    }
    list[j] = -1;
    return (list);
}

char **get_list_string(char *buff, int *i, int size)
{
    int nb_list = 0;
    int j = 0;
    char **list = NULL;

    for (j = *i; buff[j] != '\n' && buff[j] != '\0'; j++)
        if (buff[j] == '.')
            nb_list++;
    if (nb_list == 0)
        return (NULL);
    list = my_malloc(sizeof(char *) * (nb_list + 1));
    for (j = 0; j < nb_list; *i += get_size_dot(buff, *i) + 1, j++)
        list[j] = get_string_dot(buff, *i);
    list[j] = NULL;
    return (list);
}

stat_t *get_stat(char *buff, int *i)
{
    stat_t *stats = my_malloc(sizeof(stat_t));
    int j = 0;
    int list = 0;
    stat_t *(*set_npc_stat[])(stat_t *, int) = {npc_stat_level, npc_stat_hp,
    npc_stat_weapon, npc_stat_chest, npc_stat_leg, npc_stat_init,
    npc_stat_dodge, npc_stat_crit, npc_stat_stamina, npc_stat_regen,
    npc_stat_dodge_acc};

    for (j = *i; buff[j] != '\n' && buff[j] != '\0'; j++)
        if (buff[j] == '.')
            list++;
    if (list == 0)
        return (NULL);
    for (j = 0; j < list; *i += get_size_dot(buff, *i) + 1, j++)
        stats = (*set_npc_stat[j])(stats, my_atoi_dot(buff, *i));
    return (stats);
}

npc_t npc_pos_x(npc_t npc, int i, char *buff, int size)
{
    npc.pos.x = my_atoi_n(buff, i);
    return (npc);
}
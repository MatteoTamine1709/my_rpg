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

npc_t npc_speed(npc_t npc, int i, char *buff, int size)
{
    npc.walk_speed = my_atoi_n(buff, i);
    return (npc);
}

npc_t npc_stat(npc_t npc, int i, char *buff, int size)
{
    npc.stat = get_stat(buff, &i);
    return (npc);
}

npc_t npc_items(npc_t npc, int i, char *buff, int size)
{
    int nb_items = 0;

    for (int j = i; buff[j] != '\n' && buff[j] != '\0'; j++)
        if (buff[j] == '.')
            nb_items++;
    npc.nb_items = nb_items;
    npc.items = get_list(buff, &i, size);
    return (npc);
}

npc_t npc_weapons(npc_t npc, int i, char *buff, int size)
{
    int nb_weapons = 0;

    for (int j = i; buff[j] != '\n' && buff[j] != '\0'; j++)
        if (buff[j] == '.')
            nb_weapons++;
    npc.nb_weapons = nb_weapons;
    npc.weapons = get_list(buff, &i, size);
    return (npc);
}
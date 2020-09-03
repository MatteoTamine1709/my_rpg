/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** set_npc_var4
*/

#include "game.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "functions.h"

npc_t npc_sound(npc_t npc, int i, char *buff, int size)
{
    npc.sound_path = get_string(buff, i);
    return (npc);
}

npc_t npc_texture(npc_t npc, int i, char *buff, int size)
{
    npc.texture_path = get_string(buff, i);
    return (npc);
}

npc_t npc_texture_fight(npc_t npc, int i, char *buff, int size)
{
    npc.texture_path_fight = get_string(buff, i);
    return (npc);
}

npc_t npc_text(npc_t npc, int i, char *buff, int size)
{
    npc.text = my_atoi_n(buff, i);
    return (npc);
}

npc_t npc_movements(npc_t npc, int i, char *buff, int size)
{
    int nb_movements = 0;

    for (int j = i; buff[j] != '\n' && buff[j] != '\0'; j++)
        if (buff[j] == '.')
            nb_movements++;
    npc.nb_movements = nb_movements / 2;
    npc.movements = get_movements(buff, &i);
    return (npc);
}
/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** set_npc_var3
*/

#include "game.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "functions.h"

npc_t npc_pos_y(npc_t npc, int i, char *buff, int size)
{
    npc.pos.y = my_atoi_n(buff, i);
    return (npc);
}

npc_t npc_hitbox_x(npc_t npc, int i, char *buff, int size)
{
    npc.hitbox_size.x = my_atoi_n(buff, i);
    return (npc);
}

npc_t npc_hitbox_y(npc_t npc, int i, char *buff, int size)
{
    npc.hitbox_size.y = my_atoi_n(buff, i);
    return (npc);
}

npc_t npc_type(npc_t npc, int i, char *buff, int size)
{
    npc.type = my_atoi_n(buff, i);
    return (npc);
}

npc_t npc_frame_count(npc_t npc, int i, char *buff, int size)
{
    npc.frame_count = my_atoi_n(buff, i);
    return (npc);
}
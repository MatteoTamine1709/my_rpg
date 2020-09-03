/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** load_npc2
*/

#include "game.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "functions.h"

npc_t *load_npc_info(char *buff, int size, npc_t *npcs, int nb_npc)
{
    int c_npc = 0;
    int index = 0;
    npc_t (*set_npc_var[])(npc_t, int, char *, int) = {npc_pos_x, npc_pos_y,
        npc_hitbox_x, npc_hitbox_y, npc_type, npc_frame_count, npc_sound,
        npc_texture, npc_texture_fight, npc_text, npc_movements,
        npc_speed, npc_stat, npc_items, npc_weapons};

    for (int i = get_size_n(buff, 0) + 1; i < size;
        i += (get_size_n(buff, i) + 1)) {
        if (index < 15)
            npcs[c_npc] = (*set_npc_var[index])(npcs[c_npc], i, buff, size);
        index++;
        if (next_info(buff[i], (int *[3]) {&c_npc, &nb_npc, &index}) == 1)
            return (npcs);
    }
    return (npcs);
}
/*
** EPITECH PROJECT, 2024
** MUL_my_rpg_2019
** File description:
** MUL_my_rpg_2019
*/

#ifndef MUL_MY_RPG_2019_QUEST_H
#define MUL_MY_RPG_2019_QUEST_H

typedef struct quest {
    int type;
    int status;
    char *map_npc_receiver;
    int index_npc_receiver;
    char *map_npc_talk;
    int index_npc_talk;
}quest_t;

#endif //MUL_MY_RPG_2019_QUEST_H

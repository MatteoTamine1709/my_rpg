/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** set_npc_stat3
*/

#include "game.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "functions.h"

stat_t *npc_stat_init(stat_t *stat, int i)
{
    stat->speed = i;
    return (stat);
}
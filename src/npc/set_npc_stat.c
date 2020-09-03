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

stat_t *npc_stat_dodge(stat_t *stat, int i)
{
    stat->dodge = i;
    return (stat);
}

stat_t *npc_stat_crit(stat_t *stat, int i)
{
    stat->crit = i;
    return (stat);
}

stat_t *npc_stat_stamina(stat_t *stat, int i)
{
    stat->stamina = i;
    stat->max_stamina = i;
    return (stat);
}

stat_t *npc_stat_regen(stat_t *stat, int i)
{
    stat->regen_stamina = i;
    return (stat);
}

stat_t *npc_stat_dodge_acc(stat_t *stat, int i)
{
    stat->dodge_accurancy = i;
    return (stat);
}
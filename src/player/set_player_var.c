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

stat_t *player_stat_level(stat_t *stat, int i)
{
    stat->level = i;
    return (stat);
}

stat_t *player_stat_hp(stat_t *stat, int i)
{
    stat->max_hp = i;
    stat->hp = i;
    return (stat);
}

stat_t *player_stat_weapon(stat_t *stat, int i)
{
    stat->weapon_index = i;
    return (stat);
}

stat_t *player_stat_chest(stat_t *stat, int i)
{
    stat->chest_index = i;
    return (stat);
}

stat_t *player_stat_leg(stat_t *stat, int i)
{
    stat->leg_index = i;
    return (stat);
}
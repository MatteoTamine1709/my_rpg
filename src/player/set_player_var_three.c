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

stat_t *player_stat_dodge_acc(stat_t *stat, int i)
{
    stat->dodge_accurancy = i;
    return (stat);
}
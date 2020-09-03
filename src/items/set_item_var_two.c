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

item_t item_hp(item_t item, int i, char *buff)
{
    item.hp = my_atoi_n(buff, i);
    return (item);
}

item_t item_speed(item_t item, int i, char *buff)
{
    item.speed = my_atoi_n(buff, i);
    return (item);
}

item_t item_stamina(item_t item, int i, char *buff)
{
    item.stamina = my_atoi_n(buff, i);
    return (item);
}

item_t item_agility(item_t item, int i, char *buff)
{
    item.dodge = my_atoi_n(buff, i);
    return (item);
}

item_t item_crit(item_t item, int i, char *buff)
{
    item.crit = my_atoi_n(buff, i);
    return (item);
}
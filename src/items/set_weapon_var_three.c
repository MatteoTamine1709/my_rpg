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

weapon_t weapon_cds(weapon_t weapon, int i, char *buff)
{
    weapon.cds = get_list(buff, &i, 0);
    return (weapon);
}

weapon_t weapon_malus_speed(weapon_t weapon, int i, char *buff)
{
    weapon.malus_speed = my_atoi_n(buff, i);
    return (weapon);
}

weapon_t weapon_malus_stamina(weapon_t weapon, int i, char *buff)
{
    weapon.malus_stamina = my_atoi_n(buff, i);
    return (weapon);
}

weapon_t weapon_malus_agility(weapon_t weapon, int i, char *buff)
{
    weapon.malus_agility = my_atoi_n(buff, i);
    return (weapon);
}

weapon_t weapon_malus_crit(weapon_t weapon, int i, char *buff)
{
    weapon.malus_crit = my_atoi_n(buff, i);
    return (weapon);
}
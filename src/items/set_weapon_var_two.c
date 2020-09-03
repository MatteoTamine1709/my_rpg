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

weapon_t weapon_damage(weapon_t weapon, int i, char *buff)
{
    weapon.damage = my_atoi_n(buff, i);
    return (weapon);
}

weapon_t weapon_level_power(weapon_t weapon, int i, char *buff)
{
    weapon.level_power = my_atoi_n(buff, i);
    return (weapon);
}

weapon_t weapon_crit(weapon_t weapon, int i, char *buff)
{
    weapon.crit = my_atoi_n(buff, i);
    return (weapon);
}

weapon_t weapon_nb_shot(weapon_t weapon, int i, char *buff)
{
    weapon.nb_shot = my_atoi_n(buff, i);
    return (weapon);
}

weapon_t weapon_stamina(weapon_t weapon, int i, char *buff)
{
    weapon.stamina = my_atoi_n(buff, i);
    return (weapon);
}

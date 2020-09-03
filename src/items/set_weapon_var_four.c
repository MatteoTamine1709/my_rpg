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

weapon_t weapon_malus_stun(weapon_t weapon, int i, char *buff)
{
    weapon.malus_stun = my_atoi_n(buff, i);
    return (weapon);
}
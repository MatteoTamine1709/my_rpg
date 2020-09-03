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

weapon_array *set_weapon_pointer(void)
{
    weapon_array *set_weapon_var = my_malloc(sizeof(weapon_array) * 16);

    set_weapon_var[0] = weapon_name;
    set_weapon_var[1] = weapon_price;
    set_weapon_var[2] = weapon_texture;
    set_weapon_var[3] = weapon_texture_fight;
    set_weapon_var[4] = weapon_nb_frame_dodges;
    set_weapon_var[5] = weapon_damage;
    set_weapon_var[6] = weapon_level_power;
    set_weapon_var[7] = weapon_crit;
    set_weapon_var[8] = weapon_nb_shot;
    set_weapon_var[9] = weapon_stamina;
    set_weapon_var[10] = weapon_cds;
    set_weapon_var[11] = weapon_malus_speed;
    set_weapon_var[12] = weapon_malus_stamina;
    set_weapon_var[13] = weapon_malus_agility;
    set_weapon_var[14] = weapon_malus_crit;
    set_weapon_var[15] = weapon_malus_stun;
    return (set_weapon_var);
}
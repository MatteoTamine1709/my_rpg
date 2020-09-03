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

weapon_t weapon_name(weapon_t weapon, int i, char *buff)
{
    weapon.name = get_string(buff, i);
    return (weapon);
}

weapon_t weapon_price(weapon_t weapon, int i, char *buff)
{
    weapon.price = my_atoi_n(buff, i);
    return (weapon);
}

weapon_t weapon_texture(weapon_t weapon, int i, char *buff)
{
    weapon.texture_path = get_string(buff, i);
    return (weapon);
}

weapon_t weapon_texture_fight(weapon_t weapon, int i, char *buff)
{
    if (buff[i] == '\n')
        return (weapon);
    weapon.texture_path_fight = malloc(sizeof(char *) * 4);
    weapon.nb_frame_anim = malloc(sizeof(int) * 4);
    for (int j = 0; j < 4; j++) {
        weapon.nb_frame_anim[j] = my_atoi_dot(buff, i);
        i += get_size_dot(buff, i) + 1;
        weapon.texture_path_fight[j] = my_strcat(my_strcat
        ("ressources/", get_string_dot(buff, i)), ".png");
        i += get_size_dot(buff, i) + 1;
    }
    return (weapon);
}

weapon_t weapon_nb_frame_dodges(weapon_t weapon, int i, char *buff)
{
    weapon.nb_frame_dodges = get_list(buff, &i, 0);
    return (weapon);
}
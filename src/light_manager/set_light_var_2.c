/*
** EPITECH PROJECT, 2024
** MUL_my_rpg_2019
** File description:
** MUL_my_rpg_2019
*/

#include "game.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "functions.h"

light_t light_color_blue(light_t light, int i, char *buff)
{
    light.color.b = my_atoi_n(buff, i);
    return (light);
}

light_t light_color_alpha(light_t light, int i, char *buff)
{
    light.color.a = my_atoi_n(buff, i);
    return (light);
}

light_t light_intensity_a(light_t light, int i, char *buff)
{
    light.intensity_a = my_atoi_n(buff, i);
    return (light);
}

light_t light_intensity_b(light_t light, int i, char *buff)
{
    light.intensity_b = my_atoi_n(buff, i);
    return (light);
}

light_t light_nb_frame(light_t light, int i, char *buff)
{
    light.nb_frame_switch =  my_atoi_n(buff, i);
    return (light);
}
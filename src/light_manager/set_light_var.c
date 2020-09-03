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

light_t light_pos_x(light_t light, int i, char *buff)
{
    light.pos.x = my_atoi_n(buff, i);
    return (light);
}

light_t light_pos_y(light_t light, int i, char *buff)
{
    light.pos.y = my_atoi_n(buff, i);
    return (light);
}

light_t light_radius(light_t light, int i, char *buff)
{
    light.radius = my_atoi_n(buff, i);
    return (light);
}

light_t light_color_red(light_t light, int i, char *buff)
{
    light.color.r = my_atoi_n(buff, i);
    return (light);
}

light_t light_color_green(light_t light, int i, char *buff)
{
    light.color.g = my_atoi_n(buff, i);
    return (light);
}
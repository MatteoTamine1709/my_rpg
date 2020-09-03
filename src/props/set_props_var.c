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

prop_t prop_pos_x(prop_t prop, int i, char *buff)
{
    prop.pos.x = my_atoi_n(buff, i);
    return (prop);
}

prop_t prop_pos_y(prop_t prop, int i, char *buff)
{
    prop.pos.y = my_atoi_n(buff, i);
    return (prop);
}

prop_t prop_hitbox_x(prop_t prop, int i, char *buff)
{
    prop.hitbox_size.x = my_atoi_n(buff, i);
    return (prop);
}

prop_t prop_hitbox_y(prop_t prop, int i, char *buff)
{
    prop.hitbox_size.y = my_atoi_n(buff, i);
    return (prop);
}

prop_t prop_texture(prop_t prop, int i, char *buff)
{
    prop.texture_path = get_string(buff, i);
    return (prop);
}
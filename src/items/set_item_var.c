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

item_t item_name(item_t item, int i, char *buff)
{
    item.name = get_string(buff, i);
    return (item);
}

item_t item_price(item_t item, int i, char *buff)
{
    item.price = my_atoi_n(buff, i);
    return (item);
}

item_t item_texture(item_t item, int i, char *buff)
{
    item.texture_path = get_string(buff, i);
    return (item);
}

item_t item_type(item_t item, int i, char *buff)
{
    item.type = my_atoi_n(buff, i);
    return (item);
}

item_t item_level_power(item_t item, int i, char *buff)
{
    item.level_power = my_atoi_n(buff, i);
    return (item);
}
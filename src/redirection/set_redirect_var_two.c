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

redirect_t redirect_name(redirect_t redirect, int i, char *buff)
{
    redirect.redirect_name = get_string(buff, i);
    return (redirect);
}

redirect_t redirect_dest_pos_x(redirect_t redirect, int i, char *buff)
{
    redirect.dest_pos.x = my_atoi_n(buff, i);
    return (redirect);
}

redirect_t redirect_dest_pos_y(redirect_t redirect, int i, char *buff)
{
    redirect.dest_pos.y = my_atoi_n(buff, i);
    return (redirect);
}

redirect_t redirect_dest_size_x(redirect_t redirect, int i, char *buff)
{
    redirect.dest_size.x = my_atoi_n(buff, i);
    return (redirect);
}

redirect_t redirect_dest_size_y(redirect_t redirect, int i, char *buff)
{
    redirect.dest_size.y = my_atoi_n(buff, i);
    return (redirect);
}
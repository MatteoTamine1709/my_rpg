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

redirect_t redirec_pos_x(redirect_t redirect, int i, char *buff)
{
    redirect.pos.x = my_atoi_n(buff, i);
    return (redirect);
}

redirect_t redirect_pos_y(redirect_t redirect, int i, char *buff)
{
    redirect.pos.y = my_atoi_n(buff, i);
    return (redirect);
}

redirect_t redirect_hitbox_x(redirect_t redirect, int i, char *buff)
{
    redirect.hitbox_size.x = my_atoi_n(buff, i);
    return (redirect);
}

redirect_t redirect_hitbox_y(redirect_t redirect, int i, char *buff)
{
    redirect.hitbox_size.y = my_atoi_n(buff, i);
    return (redirect);
}
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

map_t *move(char *filepath, game_t *game)
{
    map_t *dest;

    dest = create_map(my_strcat(filepath, game->current_map));
    return (dest);
}
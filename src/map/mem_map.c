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

int **malloc_map(void)
{
    int **map = my_malloc(sizeof(int *) * 16);

    for (int j = 0; j < 16; j++) {
        map[j] = my_malloc(sizeof(int) * 9);
        for (int k = 0; k < 9; k++)
            map[j][k] = -1;
    }
    return (map);
}
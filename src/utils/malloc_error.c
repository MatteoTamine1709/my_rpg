/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** game_init
*/

#include "game.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>
#include "functions.h"

int next_info(char c, int **arr)
{
    if (c == '/') {
        (*arr[0])++;
        if ((*arr[0]) == (*arr[1])) {
            return (1);
        }
        (*arr[2]) = 0;
    }
    return (0);
}

void *my_malloc(int size)
{
    void *val;

    if (size < 0) {
        ERR_MALLOC = 1;
        free_all_list();
        return (NULL);
    }
    val = malloc(size);
    if (val == NULL && size != 0) {
        ERR_MALLOC = 1;
        free_all_list();
        return (NULL);
    }
    add_free_list(val);
    return (val);
}
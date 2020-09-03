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
#include "my.h"

int get_size_n(char *buff, int index)
{
    int size = 0;

    for (size = 0; buff[size + index] != '\n' &&
        buff[size + index] != '\0'; size++) {}
    return (size);
}

int get_size_dot(char *buff, int index)
{
    int size = 0;

    for (size = 0; buff[size + index] != '.' && buff[size + index] != '\0' &&
        buff[size + index] != '\n' && buff[size + index] != '\0'; size++) {}
    return (size);
}
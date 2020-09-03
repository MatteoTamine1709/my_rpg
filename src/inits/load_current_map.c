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

char *load_current_map(char *filepath)
{
    int fd = open(filepath, O_RDONLY);
    char buff[2000];
    int size;

    if (fd == -1)
        return NULL;
    size = read(fd, buff, sizeof(char) * 2000);
    if (size < 2)
        return (NULL);
    buff[size] = '\0';
    return (get_string(buff, 0));
}
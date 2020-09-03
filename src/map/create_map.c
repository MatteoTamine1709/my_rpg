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

int get_start(char *buff)
{
    int i = 0;
    int n = 0;

    for (i = 0; n < 4; i++)
        if (buff[i] == '\n')
            n++;
    return (i);
}

int get_value(sfVector2i pos, int i, char *buff, int **map)
{
    char *string = get_string_dot(buff, i);

    if (string != NULL) {
        map[pos.x][pos.y] = my_atoi_dot(string, 0);
        i += get_size_dot(buff, i);
    } else {
        map[pos.x][pos.y] = -1;
    }
    return (i);
}

int **init_map(char *buff, int size)
{
    int x = 0;
    int y = 0;
    int **map = malloc_map();

    for (int i = get_start(buff); i < size; x++, i++) {
        while (buff[i] == '\n') {
            i++;
            y++;
            x = 0;
        }
        if (x == 16) {
            y++;
            x = 0;
        }
        if (y == 9)
            break;
        i = get_value((sfVector2i) {x, y}, i, buff, map);
    }
    return (map);
}

map_t *create_map(char *map_path)
{
    map_t *map = malloc(sizeof(map_t));
    int fd = open(map_path, O_RDONLY);
    char buff[1000];
    int size = 0;

    if (fd == -1)
        return (NULL);
    size = read(fd, buff, sizeof(char) * 10000);
    buff[size] = '\0';
    if (fd == -1)
        return (NULL);
    if (size < 2)
        return (NULL);
    map->map = init_map(buff, size);
    map->top = get_top(buff);
    map->right = get_right(buff);
    map->bot = get_bot(buff);
    map->left = get_left(buff);
    close(fd);
    return (map);
}
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

int *load_effect_info(char *buff, int size, int *effects, int nb_effect)
{
    int index = 0;

    for (int i = get_size_n(buff, 0) + 1; index < nb_effect;
        i += (get_size_n(buff, i) + 1)) {
        effects[index] = my_atoi_dot(buff, i);
        index++;
    }
    return (effects);
}

int *load_effect(char *filepath, game_t *game)
{
    int fd = open(filepath, O_RDONLY);
    char buff[2000];
    int size;
    int nb_effect = 0;
    int *effects;
    game->nb_effect = 0;

    if (fd == -1)
        return NULL;
    size = read(fd, buff, sizeof(char) * 2000);
    if (size < 2)
        return (NULL);
    buff[size] = '\0';
    nb_effect = my_atoi_dot(buff, 0);
    effects = my_malloc(sizeof(int) * nb_effect);
    for (int i = 0; i < nb_effect; i++)
        effects[i] = -1;
    effects = load_effect_info(buff, size, effects, nb_effect);
    game->nb_effect = nb_effect;
    return (effects);
}
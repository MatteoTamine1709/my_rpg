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

char *get_string(char *buff, int index)
{
    int size = 0;
    char *result = NULL;

    for (size = 0; buff[size + index] != '\n' && buff[size + index] != '\0';
    size++);
    if (size == 0)
        return (NULL);
    result = malloc(sizeof(char) * (size + 1));
    for (int i = 0; i < size; i++)
        result[i] = buff[i + index];
    result[size] = '\0';
    return (result);
}

char *get_string_dot(char *buff, int index)
{
    int size = 0;
    char *result = NULL;

    for (size = 0; buff[size + index] != '.' && buff[size + index] != '\0' &&
        buff[size + index] != ' '; size++) {}
    if (size == 0)
        return (NULL);
    result = malloc(sizeof(char) * (size + 1));
    for (int i = 0; i < size; i++)
        result[i] = buff[i + index];
    result[size] = '\0';
    return (result);
}

char *my_strdup(char *src)
{
    int size = my_strlen(src);
    char *dest = malloc(sizeof(char) * (size + 1));

    for (int i = 0; i < size; i++)
        dest[i] = src[i];
    dest[size] = '\0';
    return (dest);
}

char *my_strcat(char *dest, char *src)
{
    size_t dest_len = my_strlen(dest);
    size_t src_len = my_strlen(src);
    size_t i;
    char *dest_dest = malloc(sizeof(char) * (dest_len + src_len + 1));

    for (i = 0; dest[i] != '\0' ; i++)
        dest_dest[i] = dest[i];
    for (i = 0; src[i] != '\0'; i++)
        dest_dest[dest_len + i] = src[i];
    dest_dest[dest_len + i] = '\0';
    return (dest_dest);
}

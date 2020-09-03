/*
** EPITECH PROJECT, 2020
** test
** File description:
** main
*/

#include "game.h"
#include "functions.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

char *get_top(char *buff)
{
    int i = 0;
    char *text = NULL;

    for (i = 0; buff[i] != '\n'; i++);
    text = my_malloc(sizeof(char) * (i + 1));
    for (i = 0; buff[i] != '\n'; i++)
        text[i] = buff[i];
    text[i] = '\0';
    return (text);
}

char *get_right(char *buff)
{
    int i = 0;
    int nb = 0;
    char *text = NULL;

    for (i = 0; buff[i] != '\n'; i++);
    i++;
    nb = i;
    for (i; buff[i] != '\n'; i++);
    text = my_malloc(sizeof(char) * (i - nb + 1));
    for (i = nb; buff[i] != '\n'; i++)
        text[i - nb] = buff[i];
    text[i - nb] = '\0';
    return (text);
}

char *get_bot(char *buff)
{
    int i = 0;
    int nb = 0;
    char *text = NULL;

    for (i = 0; buff[i] != '\n'; i++);
    i++;
    for (i; buff[i] != '\n'; i++);
    i++;
    nb = i;
    for (i; buff[i] != '\n'; i++);
    text = my_malloc(sizeof(char) * (i + 1 - nb));
    for (i = nb; buff[i] != '\n'; i++)
        text[i - nb] = buff[i];
    text[i - nb] = '\0';
    return (text);
}

char *get_left(char *buff)
{
    int i = 0;
    int nb = 0;
    char *text = NULL;

    for (i = 0; buff[i] != '\n'; i++);
    i++;
    for (i; buff[i] != '\n'; i++);
    i++;
    for (i; buff[i] != '\n'; i++);
    i++;
    nb = i;
    for (i; buff[i] != '\n'; i++);
    text = my_malloc(sizeof(char) * (i + 1 - nb));
    for (i = nb; buff[i] != '\n'; i++)
        text[i - nb] = buff[i];
    text[i - nb] = '\0';
    return (text);
}
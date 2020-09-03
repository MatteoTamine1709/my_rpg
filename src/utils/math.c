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
#include <math.h>
#include "functions.h"
#include <stdio.h>

int my_atoi(char *str)
{
    int res = 0;
    int minus = 1;
    int start = 0;

    if (str[0] == '-') {
        start++;
        minus = -1;
    }
    for (int i = start; str[i] != '\0'; ++i)
        res = res * 10 + str[i] - '0';
    return (res * minus);
}

int my_atoi_n(char *str, int index)
{
    int res = 0;
    int minus = 1;

    if (str[index] == '-') {
        index++;
        minus = -1;
    }
    if (str[index] == '\n')
        return (-1);
    for (int i = index; str[i] != '\n'; ++i)
        res = res * 10 + str[i] - '0';
    return (res * minus);
}

int my_atoi_dot(char *str, int index)
{
    int res = 0;
    int minus = 1;

    if (str[index] == '-') {
        index++;
        minus = -1;
    }
    if (str[index] == '.')
        return (-1);
    for (int i = index; str[i] != '.' && str[i] != '\0'; ++i)
        res = res * 10 + str[i] - '0';
    return (res * minus);
}

float dist(float x1, float y1, float x2, float y2)
{
    float x_dist = x1 - x2;
    float y_dist = y1 - y2;
    float dist;

    x_dist *= x_dist;
    y_dist *= y_dist;
    dist = sqrtf(x_dist + y_dist);
    return (dist);
}
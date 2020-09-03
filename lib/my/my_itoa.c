/*
** EPITECH PROJECT, 2020
** test_menu
** File description:
** my_itoa
*/

#include <stdio.h>
#include <stdlib.h>

int nb_size(int nb)
{
    int temp = 1;
    if (nb < 0)
        nb *= 1;

    for (; nb > 9; temp++) {
        nb /= 10;
    }
    return (temp);
}

char *my_itoa(int nb)
{
    int size = nb_size(nb);
    int neg = 0;
    char *str;

    if (nb < 0) {
        neg = 1;
        nb *= -1;
    }
    str = malloc(sizeof(char) * (size + 1 + neg));
    for (int i = size + neg - 1; i >= neg; i--) {
        str[i] = (nb % 10) + '0';
        nb = nb / 10;
    }
    if (neg == 1)
        str[0] = '-';
    str[size + neg] = '\0';
    return (str);
}
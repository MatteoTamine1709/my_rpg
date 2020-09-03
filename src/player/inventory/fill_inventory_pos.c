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
#include "my.h"

sfVector2f scale_pos_inventory(int i, inventory_t *inventory)
{
    sfVector2f pos = (sfVector2f) {-1, -1};

    i -= 5;
    int col = i % 3;
    i -= (i % 3);
    int row = i % 4;
    pos = (sfVector2f) {758 + (150 * col), 530 + (140 * row)};
    return (pos);
}

sfVector2f get_pos_from_index(int i, inventory_t *inventory)
{
    sfVector2f pos = (sfVector2f) {100, 100};

    switch (i) {
        case 0:
            return ((sfVector2f) {689, 83});
        case 1:
            return ((sfVector2f) {1139, 124});
        case 2:
            return ((sfVector2f) {1139, 270});
        case 3:
            return ((sfVector2f) {689, 234});
        case 4:
            return ((sfVector2f) {689, 384});
    }
    if (i >= 5)
        pos = scale_pos_inventory(i, inventory);
    return (pos);
}
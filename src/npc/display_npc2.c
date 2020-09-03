/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** display_npc2
*/

#include "game.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "functions.h"
#include "my.h"

sfIntRect get_rect_pos(game_t *game, npc_t *npc)
{
    sfIntRect rect = (sfIntRect) {0, 0, 200, 100};
    if (npc->text_cursor >= 100)
        rect.top = 100;
    rect.left = (npc->text % 10) * 200;
    return (rect);
}
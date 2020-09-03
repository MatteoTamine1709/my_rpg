/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** searching uncase.c
*/

#include "game.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <math.h>
#include "functions.h"
#include "my.h"

void checking_wich_uncase_fst(sfVector2i mouse, game_t *game)
{
    if (mouse.x >= 680 && mouse.y >= 230 && mouse.x <= 800 && mouse.y <= 335
    && game->player->inventory->weapons[3].name == NULL
    && game->player->inventory->items[3].name == NULL
    && game->selected_case_inv != 4)
        game->unselected_case_inv = 4;
    if (mouse.x >= 680 && mouse.y >= 365 && mouse.x <= 800 && mouse.y <= 475
    && game->player->inventory->weapons[4].name == NULL
    && game->player->inventory->items[4].name == NULL
    && game->selected_case_inv != 5)
        game->unselected_case_inv = 5;
    if (mouse.x >= 745 && mouse.y >= 520 && mouse.x <= 865 && mouse.y <= 630
    && game->player->inventory->weapons[5].name == NULL
    && game->player->inventory->items[5].name == NULL
    && game->selected_case_inv != 6)
        game->unselected_case_inv = 6;
    if (mouse.x >= 895 && mouse.y >= 520 && mouse.x <= 1015 && mouse.y <= 630
    && game->player->inventory->weapons[6].name == NULL
    && game->player->inventory->items[6].name == NULL
    && game->selected_case_inv != 7)
        game->unselected_case_inv = 7;
}

void checking_wich_uncase_scd(sfVector2i mouse, game_t *game)
{
    if (mouse.x >= 1045 && mouse.y >= 520 && mouse.x <= 1165 && mouse.y <= 630
    && game->player->inventory->weapons[7].name == NULL
    && game->player->inventory->items[7].name == NULL
    && game->selected_case_inv != 8)
        game->unselected_case_inv = 8;
    if (mouse.x >= 745 && mouse.y >= 660 && mouse.x <= 865 && mouse.y <= 770
    && game->player->inventory->weapons[8].name == NULL
    && game->player->inventory->items[8].name == NULL
    && game->selected_case_inv != 9)
        game->unselected_case_inv = 9;
    if (mouse.x >= 895 && mouse.y >= 660 && mouse.x <= 1015 && mouse.y <= 770
    && game->player->inventory->weapons[9].name == NULL
    && game->player->inventory->items[9].name == NULL
    && game->selected_case_inv != 10)
        game->unselected_case_inv = 10;
    if (mouse.x >= 1045 && mouse.y >= 660 && mouse.x <= 1165 && mouse.y <= 770
    && game->player->inventory->weapons[10].name == NULL
    && game->player->inventory->items[10].name == NULL
    && game->selected_case_inv != 11)
        game->unselected_case_inv = 11;
}

void checking_wich_uncase_thd(sfVector2i mouse, game_t *game)
{
    if (mouse.x >= 745 && mouse.y >= 800 && mouse.x <= 865 && mouse.y <= 905
    && game->player->inventory->weapons[11].name == NULL
    && game->player->inventory->items[11].name == NULL
    && game->selected_case_inv != 12)
        game->unselected_case_inv = 12;
    if (mouse.x >= 895 && mouse.y >= 800 && mouse.x <= 1015 && mouse.y <= 905
    && game->player->inventory->weapons[12].name == NULL
    && game->player->inventory->items[12].name == NULL
    && game->selected_case_inv != 13)
        game->unselected_case_inv = 13;
    if (mouse.x >= 1045 && mouse.y >= 800 && mouse.x <= 1165 && mouse.y <= 905
    && game->player->inventory->weapons[13].name == NULL
    && game->player->inventory->items[13].name == NULL
    && game->selected_case_inv != 14)
        game->unselected_case_inv = 14;
    if (mouse.x >= 745 && mouse.y >= 935 && mouse.x <= 865 && mouse.y <= 1045
    && game->player->inventory->weapons[14].name == NULL
    && game->player->inventory->items[14].name == NULL
    && game->selected_case_inv != 15)
        game->unselected_case_inv = 15;
}

void checking_wich_uncase_fht(sfVector2i mouse, game_t *game)
{
    if (mouse.x >= 895 && mouse.y >= 935 && mouse.x <= 1015 && mouse.y <= 1045
    && game->player->inventory->weapons[15].name == NULL
    && game->player->inventory->items[15].name == NULL
    && game->selected_case_inv != 16)
        game->unselected_case_inv = 16;
    if (mouse.x >= 1045 && mouse.y >= 935 && mouse.x <= 1165 && mouse.y <= 1045
    && game->player->inventory->weapons[16].name == NULL
    && game->player->inventory->items[16].name == NULL
    && game->selected_case_inv != 17)
        game->unselected_case_inv = 17;
}
/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** searching_case.c
*/

#include "game.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <math.h>
#include "functions.h"
#include "my.h"

void checking_wich_case_scd(sfVector2i mouse, game_t *game)
{
    if (mouse.x >= 1045 && mouse.y >= 520 && mouse.x <= 1165 && mouse.y <= 630)
        if (game->player->inventory->weapons[7].name != NULL
        || game->player->inventory->items[7].name != NULL)
            game->selected_case_inv = 8;
    if (mouse.x >= 745 && mouse.y >= 660 && mouse.x <= 865 && mouse.y <= 770)
        if (game->player->inventory->weapons[8].name != NULL
        || game->player->inventory->items[8].name != NULL)
            game->selected_case_inv = 9;
    if (mouse.x >= 895 && mouse.y >= 660 && mouse.x <= 1015 && mouse.y <= 770)
        if (game->player->inventory->weapons[9].name != NULL
        || game->player->inventory->items[9].name != NULL)
            game->selected_case_inv = 10;
    if (mouse.x >= 1045 && mouse.y >= 660 && mouse.x <= 1165 && mouse.y <= 770)
        if (game->player->inventory->weapons[10].name != NULL
        || game->player->inventory->items[10].name != NULL)
            game->selected_case_inv = 11;
    if (mouse.x >= 745 && mouse.y >= 800 && mouse.x <= 865 && mouse.y <= 905)
        if (game->player->inventory->weapons[11].name != NULL
        || game->player->inventory->items[11].name != NULL)
            game->selected_case_inv = 12;
}

void checking_wich_case_thd(sfVector2i mouse, game_t *game)
{
    if (mouse.x >= 895 && mouse.y >= 800 && mouse.x <= 1015 && mouse.y <= 905)
        if (game->player->inventory->weapons[12].name != NULL
        || game->player->inventory->items[12].name != NULL)
            game->selected_case_inv = 13;
    if (mouse.x >= 1045 && mouse.y >= 800 && mouse.x <= 1165 && mouse.y <= 905)
        if (game->player->inventory->weapons[13].name != NULL
        || game->player->inventory->items[13].name != NULL)
            game->selected_case_inv = 14;
    if (mouse.x >= 745 && mouse.y >= 935 && mouse.x <= 865 && mouse.y <= 1045)
        if (game->player->inventory->weapons[14].name != NULL
        || game->player->inventory->items[14].name != NULL)
            game->selected_case_inv = 15;
    if (mouse.x >= 895 && mouse.y >= 935 && mouse.x <= 1015 && mouse.y <= 1045)
        if (game->player->inventory->weapons[15].name != NULL
        || game->player->inventory->items[15].name != NULL)
            game->selected_case_inv = 16;
    if (mouse.x >= 1045 && mouse.y >= 935 && mouse.x <= 1165 && mouse.y <= 1045)
        if (game->player->inventory->weapons[16].name != NULL
        || game->player->inventory->items[16].name != NULL)
            game->selected_case_inv = 17;
}

void checking_wich_case_fst(sfVector2i mouse, game_t *game)
{
    if (mouse.x >= 680 && mouse.y >= 365 && mouse.x <= 800 && mouse.y <= 475)
        if (game->player->inventory->weapons[4].name != NULL
        || game->player->inventory->items[4].name != NULL)
            game->selected_case_inv = 5;
    if (mouse.x >= 745 && mouse.y >= 520 && mouse.x <= 865 && mouse.y <= 630)
        if (game->player->inventory->weapons[5].name != NULL
        || game->player->inventory->items[5].name != NULL)
            game->selected_case_inv = 6;
    if (mouse.x >= 895 && mouse.y >= 520 && mouse.x <= 1015 && mouse.y <= 630)
        if (game->player->inventory->weapons[6].name != NULL
        || game->player->inventory->items[6].name != NULL)
            game->selected_case_inv = 7;
}

sfVector2f get_pos_from_index_trying(int i)
{
    sfVector2f pos = (sfVector2f) {100, 100};

    if (i == 1)
        pos = (sfVector2f) {689, 83};
    if (i == 2)
        pos = (sfVector2f) {1125, 115};
    if (i == 3)
        pos = (sfVector2f) {1125, 260};
    if (i == 4)
        pos = (sfVector2f) {689, 225};
    if (i == 5)
        pos = (sfVector2f) {689, 365};
    if (i == 6)
        pos = (sfVector2f) {745, 520};
    if (i == 7)
        pos = (sfVector2f) {895, 520};
    if (i == 8)
        pos = (sfVector2f) {1045, 520};
    pos = get_pos_from_index_trying_scd(i, pos);
    return (pos);
}

sfVector2f get_pos_from_index_trying_scd(int i, sfVector2f pos)
{
    if (i == 9)
        pos = (sfVector2f) {745, 660};
    if (i == 10)
        pos = (sfVector2f) {895, 660};
    if (i == 11)
        pos = (sfVector2f) {1045, 660};
    if (i == 12)
        pos = (sfVector2f) {745, 800};
    if (i == 13)
        pos = (sfVector2f) {895, 800};
    if (i == 14)
        pos = (sfVector2f) {1045, 800};
    if (i == 15)
        pos = (sfVector2f) {745, 935};
    if (i == 16)
        pos = (sfVector2f) {895, 935};
    if (i == 17)
        pos = (sfVector2f) {1045, 935};
    return (pos);
}
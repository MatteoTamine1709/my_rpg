/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** switching_case2.c
*/

#include "game.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <math.h>
#include "functions.h"
#include "my.h"

void switching_items_weapons_fht(game_t *game)
{
    game->player->inventory->weapons[game->unselected_case_inv - 1].sprite
    = game->player->inventory->weapons[game->selected_case_inv - 1].sprite;
       game->player->inventory->weapons[game->unselected_case_inv - 1].
       texture_fight
    = game->player->inventory->weapons[game->selected_case_inv - 1].
    texture_fight;
       game->player->inventory->weapons[game->unselected_case_inv - 1].
       texture_path_fight
    = game->player->inventory->weapons[game->selected_case_inv - 1].
    texture_path_fight;
       game->player->inventory->weapons[game->unselected_case_inv - 1].texture
    = game->player->inventory->weapons[game->selected_case_inv - 1].texture;
       game->player->inventory->weapons[game->unselected_case_inv-1].texture_path
    = game->player->inventory->weapons[game->selected_case_inv-1].texture_path;
       game->player->inventory->weapons[game->unselected_case_inv - 1].cds
    = game->player->inventory->weapons[game->selected_case_inv - 1].cds;
       game->player->inventory->weapons[game->unselected_case_inv - 1].
       nb_frame_dodges
    = game->player->inventory->weapons[game->selected_case_inv - 1].
    nb_frame_dodges;
}
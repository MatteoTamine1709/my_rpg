/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** switching_case.c
*/

#include "game.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <math.h>
#include "functions.h"
#include "my.h"

void switching_items_weapons(game_t *game)
{
    game->player->inventory->weapons[game->unselected_case_inv - 1].
    nb_frame_anim
    = game->player->inventory->weapons[game->selected_case_inv - 1].
    nb_frame_anim;
    game->player->inventory->weapons[game->unselected_case_inv - 1].
    anim_rects
    = game->player->inventory->weapons[game->selected_case_inv - 1].
    anim_rects;
    game->player->inventory->weapons[game->unselected_case_inv - 1].price
    = game->player->inventory->weapons[game->selected_case_inv - 1].price;
    game->player->inventory->weapons[game->unselected_case_inv - 1].name
    = game->player->inventory->weapons[game->selected_case_inv - 1].name;
    game->player->inventory->weapons[game->unselected_case_inv - 1].
    level_power
    = game->player->inventory->weapons[game->selected_case_inv - 1].
    level_power;
    game->player->inventory->weapons[game->unselected_case_inv - 1].
    stamina
    = game->player->inventory->weapons[game->selected_case_inv - 1].
    stamina;
}

void switching_items_weapons_scd(game_t *game)
{
    game->player->inventory->weapons[game->unselected_case_inv - 1].crit
    = game->player->inventory->weapons[game->selected_case_inv - 1].crit;
    game->player->inventory->weapons[game->unselected_case_inv - 1].
    damage
    = game->player->inventory->weapons[game->selected_case_inv - 1].
    damage;
    game->player->inventory->weapons[game->unselected_case_inv - 1].
    nb_shot
    = game->player->inventory->weapons[game->selected_case_inv - 1].
    nb_shot;
    game->player->inventory->weapons[game->unselected_case_inv - 1].
    malus_hp
    = game->player->inventory->weapons[game->selected_case_inv - 1].
    malus_hp;
    game->player->inventory->weapons[game->unselected_case_inv - 1].
    malus_speed
    = game->player->inventory->weapons[game->selected_case_inv - 1].
    malus_speed;
}

void switching_items_weapons_thd(game_t *game)
{
    game->player->inventory->weapons[game->unselected_case_inv - 1].
    malus_stamina
    = game->player->inventory->weapons[game->selected_case_inv - 1].
    malus_stamina;
    game->player->inventory->weapons[game->unselected_case_inv - 1].
    malus_agility
    = game->player->inventory->weapons[game->selected_case_inv - 1].
    malus_agility;
    game->player->inventory->weapons[game->unselected_case_inv - 1].
    malus_crit
    = game->player->inventory->weapons[game->selected_case_inv - 1].
    malus_crit;
    game->player->inventory->weapons[game->unselected_case_inv - 1].
    malus_stun
    = game->player->inventory->weapons[game->selected_case_inv - 1].
    malus_stun;
    game->player->inventory->weapons[game->selected_case_inv - 1].name = NULL;
}

void switching_item_items(game_t *game)
{
    game->player->inventory->items[game->unselected_case_inv - 1].sprite
    = game->player->inventory->items[game->selected_case_inv - 1].sprite;
    game->player->inventory->items[game->unselected_case_inv - 1].texture
    = game->player->inventory->items[game->selected_case_inv - 1].texture;
    game->player->inventory->items[game->unselected_case_inv - 1].texture_path
    = game->player->inventory->items[game->selected_case_inv - 1].texture_path;
    game->player->inventory->items[game->unselected_case_inv - 1].price
    = game->player->inventory->items[game->selected_case_inv - 1].price;
    game->player->inventory->items[game->unselected_case_inv - 1].type
    = game->player->inventory->items[game->selected_case_inv - 1].type;
    game->player->inventory->items[game->unselected_case_inv - 1].hp
    = game->player->inventory->items[game->selected_case_inv - 1].hp;
    game->player->inventory->items[game->unselected_case_inv - 1].speed
    = game->player->inventory->items[game->selected_case_inv - 1].speed;
    game->player->inventory->items[game->unselected_case_inv - 1].stamina
    = game->player->inventory->items[game->selected_case_inv - 1].stamina;
    game->player->inventory->items[game->unselected_case_inv - 1].dodge
    = game->player->inventory->items[game->selected_case_inv - 1].dodge;
    game->player->inventory->items[game->unselected_case_inv - 1].crit
    = game->player->inventory->items[game->selected_case_inv - 1].crit;
}

void switching_item_items_scd(game_t *game)
{
    game->player->inventory->items[game->unselected_case_inv - 1].name
    = game->player->inventory->items[game->selected_case_inv - 1].name;
    game->player->inventory->items[game->selected_case_inv - 1].name
    = NULL;
    game->player->inventory->items[game->unselected_case_inv - 1].level_power
    = game->player->inventory->items[game->selected_case_inv - 1].level_power;
}
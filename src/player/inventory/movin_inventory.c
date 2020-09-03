/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** movin_inventory.c
*/

#include "game.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <math.h>
#include "functions.h"
#include "my.h"

void checking_wich_case(sfVector2i mouse, game_t *game)
{
    if (mouse.x >= 680 && mouse.y >= 70 && mouse.x <= 825 && mouse.y <= 170)
        if (game->player->inventory->weapons[0].name != NULL
        || game->player->inventory->items[0].name != NULL)
            game->selected_case_inv = 1;
    if (mouse.x >= 1125 && mouse.y >= 115 && mouse.x <= 1245 && mouse.y <= 220)
        if (game->player->inventory->weapons[1].name != NULL
        || game->player->inventory->items[1].name != NULL)
            game->selected_case_inv = 2;
    if (mouse.x >= 1125 && mouse.y >= 260 && mouse.x <= 1245 && mouse.y <= 365)
        if (game->player->inventory->weapons[2].name != NULL
        || game->player->inventory->items[2].name != NULL)
            game->selected_case_inv = 3;
    if (mouse.x >= 680 && mouse.y >= 225 && mouse.x <= 800 && mouse.y <= 335)
        if (game->player->inventory->weapons[3].name != NULL
        || game->player->inventory->items[3].name != NULL)
            game->selected_case_inv = 4;
    checking_wich_case_fst(mouse, game);
    checking_wich_case_scd(mouse, game);
    checking_wich_case_thd(mouse, game);
}

void checking_wich_uncase(sfVector2i mouse, game_t *game)
{
    if (mouse.x >= 680 && mouse.y >= 70 && mouse.x <= 825 && mouse.y <= 170
    && game->player->inventory->weapons[0].name == NULL
    && game->player->inventory->items[0].name == NULL
    && game->selected_case_inv != 1)
        game->unselected_case_inv = 1;
    if (mouse.x >= 1125 && mouse.y >= 115 && mouse.x <= 1250 && mouse.y <= 225
    && game->player->inventory->weapons[1].name == NULL
    && game->player->inventory->items[1].name == NULL
    && game->selected_case_inv != 2)
        game->unselected_case_inv = 2;
    if (mouse.x >= 1125 && mouse.y >= 260 && mouse.x <= 1250 && mouse.y <= 365
    && game->player->inventory->weapons[2].name == NULL
    && game->player->inventory->items[2].name == NULL
    && game->selected_case_inv != 3)
        game->unselected_case_inv = 3;
    checking_wich_uncase_fst(mouse, game);
    checking_wich_uncase_scd(mouse, game);
    checking_wich_uncase_thd(mouse, game);
    checking_wich_uncase_fht(mouse, game);
}

void switching_items(game_t *game, int wich)
{
    sfVector2f pos = get_pos_from_index_trying(game->unselected_case_inv);

    if (wich == 1) {
        sfSprite_setPosition(game->player->inventory->weapons
        [game->selected_case_inv - 1].sprite, pos);
        sfRenderWindow_drawSprite(game->window->w,
        game->player->inventory->weapons[game->selected_case_inv - 1].sprite,
        NULL);
        switching_items_scd(game, wich);
    } else if (wich == 0) {
        sfSprite_setPosition(game->player->inventory->items
        [game->selected_case_inv - 1].sprite, pos);
        sfRenderWindow_drawSprite(game->window->w,
        game->player->inventory->items[game->selected_case_inv - 1].sprite,
        NULL);
        switching_items_scd(game, wich);
    }
}

void switching_items_scd(game_t *game, int wich)
{
    if (wich == 1) {
        switching_items_weapons(game);
        switching_items_weapons_scd(game);
        switching_items_weapons_thd(game);
        switching_items_weapons_fht(game);
    } else if (wich == 0) {
        switching_item_items(game);
        switching_item_items_scd(game);
    }
}

void handle_mouse_eventgame(sfVector2i mouse, game_t *game)
{
    if (game->selected_case_inv == 0)
        checking_wich_case(mouse, game);
    if (game->selected_case_inv != 0)
        checking_wich_uncase(mouse, game);
    if (game->player->inventory->weapons[game->selected_case_inv - 1].name
    != NULL && game->selected_case_inv != 0 && game->unselected_case_inv != 0)
        switching_items(game, 1);
    else if (game->player->inventory->items[game->selected_case_inv - 1].name
    != NULL && game->selected_case_inv != 0 && game->unselected_case_inv != 0)
        switching_items(game, 0);
    if (game->unselected_case_inv != 0 && game->selected_case_inv != 0) {
        game->selected_case_inv = 0;
        game->unselected_case_inv = 0;
    }
}
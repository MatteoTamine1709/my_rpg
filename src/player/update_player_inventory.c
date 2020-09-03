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

void move_inventory(inventory_t *inventory, int side, game_t *game)
{
    int index = 0;

    for (int j = 0; j < game->npcs[game->player->npc_interact_index].nb_items;
    j++, index++)
        sfSprite_move(game->items[game->npcs
        [game->player->npc_interact_index].items[j]].sprite, (sfVector2f)
        {1250 * (-side), 380 * (-side) + (120 * index)});
    for (int j = 0; j < game->npcs
    [game->player->npc_interact_index].nb_weapons; j++, index++)
        sfSprite_move(game->weapons[game->npcs
        [game->player->npc_interact_index].weapons[j]].sprite, (sfVector2f)
        {1250 * (-side), (380 + (120 * index)) * (-side)});
}

inventory_t *set_inventory_shop(inventory_t *inventory, int side, game_t *game)
{
    sfVector2f offset = (sfVector2f) {578 * side, 0};

    sfSprite_move(inventory->sprite, offset);
    for (int i = 0; i < 17; i++) {
        if (inventory->items[i].name)
            sfSprite_move(inventory->items[i].sprite, offset);
        if (inventory->weapons[i].name)
            sfSprite_move(inventory->weapons[i].sprite, offset);
    }
    move_inventory(inventory, side, game);
    return (inventory);
}
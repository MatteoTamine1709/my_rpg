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

inventory_t *add_item_inventory(inventory_t *inventory, item_t item, int index)
{
    sfVector2f pos;

    for (int i = 0; i < 17; i++) {
        if (!inventory->items[i].name && !inventory->weapons[i].name) {
            inventory->items[i] = copy_item(item);
            pos = get_pos_from_index(i, inventory);
            inventory->item_num[i] = index;
            sfSprite_setPosition(inventory->items[i].sprite, pos);
            break;
        }
    }
    return (inventory);
}

inventory_t *add_item_inventory_pos(inventory_t *inventory, item_t item,
    int index, int pos_inv)
{
    sfVector2f pos;

    inventory->items[pos_inv] = copy_item(item);
    pos = get_pos_from_index(pos_inv, inventory);
    inventory->item_num[pos_inv] = index;
    sfSprite_setPosition(inventory->items[pos_inv].sprite, pos);
    return (inventory);
}

inventory_t *add_weapon_inventory_pos(inventory_t *inventory, weapon_t weapon,
    int index, int pos_inv)
{
    sfVector2f pos;

    inventory->weapons[pos_inv] = copy_weapon(weapon);
    pos = get_pos_from_index(pos_inv, inventory);
    inventory->weapon_num[pos_inv] = index;
    sfSprite_setPosition(inventory->weapons[pos_inv].sprite, pos);
    return (inventory);
}

inventory_t *add_weapon_inventory(inventory_t *inventory, weapon_t weapon,
    int index)
{
    sfVector2f pos;

    for (int i = 0; i < 17; i++) {
        if (!inventory->items[i].name && !inventory->weapons[i].name) {
            inventory->weapons[i] = copy_weapon(weapon);
            inventory->weapon_num[i] = index;
            pos = get_pos_from_index(i, inventory);
            sfSprite_setPosition(inventory->weapons[i].sprite, pos);
            break;
        }
    }
    return (inventory);
}
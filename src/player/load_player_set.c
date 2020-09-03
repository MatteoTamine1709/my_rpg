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
#include "functions.h"

player_t *set_player_desgin_items(player_t *player, game_t *game)
{
    for (int i = 0; i < 17; i++) {
        player->inventory->items[i].name = NULL;
        player->inventory->weapons[i].name = NULL;
        if (player->inventory->item_num[i] != 99999)
            player->inventory = add_item_inventory_pos(player->inventory,
            game->items[player->inventory->item_num[i]],
            player->inventory->item_num[i], i);
        if (player->inventory->weapon_num[i] != 99999)
            player->inventory = add_weapon_inventory_pos(player->inventory,
            game->weapons[player->inventory->weapon_num[i]],
            player->inventory->weapon_num[i], i);
    }
    return (player);
}

player_t *set_player_design_stuff(player_t *player, game_t *game)
{
    player->shop_texture =
    sfTexture_createFromFile("ressources/shop_inventory.png", NULL);
    sfSprite_setTexture(player->shop_sprite, player->shop_texture, sfFalse);
    player->inventory->items = my_malloc(sizeof(item_t) * 17);
    player->inventory->weapons = my_malloc(sizeof(weapon_t) * 17);
    player->inventory->sprite = sfSprite_create();
    player->inventory->texture =
    sfTexture_createFromFile("ressources/player_inventory.png", NULL);
    sfSprite_setTexture(player->inventory->sprite, player->inventory->texture,
    sfFalse);
    player->inventory->bg_sprite = sfSprite_create();
    player->inventory->bg_texture =
    sfTexture_createFromFile("ressources/inventory_bg.png", NULL);
    sfSprite_setTexture(player->inventory->bg_sprite,
    player->inventory->bg_texture, sfFalse);
    set_player_desgin_items(player, game);
    return (player);
}

player_t *set_player_design(player_t *player, game_t *game)
{
    if (player->stat->weapon_index != -1)
        player->stat->weapon = game->weapons[player->stat->weapon_index];
    if (player->stat->chest_index != -1)
        player->stat->chest = game->items[player->stat->chest_index];
    if (player->stat->leg_index != - 1)
        player->stat->leg = game->items[player->stat->leg_index];
    player->sprite = sfSprite_create();
    player->rect = (sfIntRect) {0, 0, 60, 60};
    player->texture =
        sfTexture_createFromFile("ressources/player.png", NULL);
    player->texture_fight =
        sfTexture_createFromFile("ressources/fight_player.png", NULL);
    sfSprite_setTexture(player->sprite, player->texture, sfFalse);
    sfSprite_setTextureRect(player->sprite, player->rect);
    sfSprite_setPosition(player->sprite, player->pos);
    player->shop_sprite = sfSprite_create();
    player = set_player_design_stuff(player, game);
    return (player);
}
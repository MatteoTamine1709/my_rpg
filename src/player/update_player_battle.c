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

player_t *update_player_stat(player_t *player)
{
    player->stat->hp += player->stat->chest.hp;
    player->stat->max_hp += player->stat->chest.hp;
    player->stat->speed += player->stat->chest.speed;
    player->stat->max_stamina += player->stat->chest.stamina;
    player->stat->dodge += player->stat->chest.dodge;
    player->stat->crit += player->stat->chest.crit;
    player->stat->hp += player->stat->leg.hp;
    player->stat->max_hp += player->stat->leg.hp;
    player->stat->speed += player->stat->leg.speed;
    player->stat->stamina += player->stat->leg.stamina;
    player->stat->dodge += player->stat->leg.dodge;
    player->stat->crit += player->stat->leg.crit;
    return (player);
}

void set_battle_design(battle_t *battle, player_t *player)
{
    sfVector2f pos = (sfVector2f) {200, 800};
    sfVector2f scale = (sfVector2f) {100, 100};

    for (int i = 0; i < 3; i++) {
        battle->player_cds[i] = 0;
        battle->npc_cds[i] = 0;
        if (i == 0)
            battle->player_cds_rect[i] = make_rectangle(pos, scale, sfRed);
        if (i == 1)
            battle->player_cds_rect[i] = make_rectangle(pos, scale, sfGreen);
        if (i == 2)
            battle->player_cds_rect[i] = make_rectangle(pos, scale, sfBlue);
        pos.x += 200;
    }
    battle->player_speed = 0;
    battle->npc_speed = 0;
    battle->sprite_effect = sfSprite_create();
    battle->sprite_incantation = sfSprite_create();
}

battle_t *set_battle_stat(battle_t *battle, player_t *player, npc_t *npc)
{
    battle->player = player;
    battle->npc = npc;
    battle->start = 0;
    battle = reset_battle(battle);
    battle->player_cds = my_malloc(sizeof(int) * 3);
    battle->npc_cds = my_malloc(sizeof(int) * 3);
    battle->player_cds_rect = my_malloc(sizeof(sfRectangleShape *) * 3);
    battle->reaction = -1;
    battle->player->rect.top = 0;
    battle->player->rect.left = 0;
    sfSprite_setTextureRect(battle->player->sprite, battle->player->rect);
    sfSprite_setPosition(battle->player->sprite, (sfVector2f) {200, 540});
    sfSprite_setPosition(battle->npc->sprite, (sfVector2f) {1720, 540});
    return (battle);
}

battle_t *set_battle(battle_t *battle, player_t *player, npc_t *npc)
{
    if (player->inventory->weapons[0].name == NULL ||
    player->inventory->items[1].name == NULL ||
    player->inventory->items[2].name == NULL)
        return (NULL);
    battle = set_battle_stat(battle, player, npc);
    player->stat->weapon = player->inventory->weapons[0];
    player->stat->chest = player->inventory->items[1];
    player->stat->leg = player->inventory->items[2];
    player = update_player_stat(player);
    set_battle_design(battle, player);
    return (battle);
}
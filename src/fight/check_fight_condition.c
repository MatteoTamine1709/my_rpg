/*
** EPITECH PROJECT, 2020
** CSTYLE
** File description:
** main
*/

#include "game.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "functions.h"
#include "my.h"

void remove_player_stat(player_t *player)
{
    player->stat->hp -= player->stat->chest.hp;
    player->stat->max_hp -= player->stat->chest.hp;
    player->stat->speed -= player->stat->chest.speed;
    player->stat->max_stamina -= player->stat->chest.stamina;
    player->stat->dodge -= player->stat->chest.dodge;
    player->stat->crit -= player->stat->chest.crit;
    player->stat->hp -= player->stat->leg.hp;
    player->stat->max_hp -= player->stat->leg.hp;
    player->stat->speed -= player->stat->leg.speed;
    player->stat->stamina -= player->stat->leg.stamina;
    player->stat->dodge -= player->stat->leg.dodge;
    player->stat->crit -= player->stat->leg.crit;
}

void player_dead(battle_t *battle, game_t *game)
{
    remove_player_stat(battle->player);
    battle->player->destination_point = battle->player->pos;
    battle->npc->render_state = 0;
    battle->player->in_fight = 0;
    battle->npc->stat->hp = 0;
    save_npc(game);
    sfSprite_setPosition(battle->player->sprite, battle->player->pos);
    sfSprite_setPosition(battle->npc->sprite, battle->npc->pos);
    sfSprite_setTextureRect(battle->player->sprite, battle->player->rect);
    sfSprite_setTexture(battle->player->sprite, battle->player->texture,
    sfFalse);
}

void enemy_dead(battle_t *battle, game_t *game)
{
    remove_player_stat(battle->player);
    battle->player->destination_point = battle->player->pos;
    sfSprite_setPosition(battle->player->sprite, battle->player->pos);
    sfSprite_setPosition(battle->npc->sprite, battle->npc->pos);
    battle->player->in_fight = 0;
    sfSprite_setTextureRect(battle->player->sprite, battle->player->rect);
    sfSprite_setTexture(battle->player->sprite, battle->player->texture,
    sfFalse);
}

int check_if_battle_start(battle_t *battle, game_t *game)
{
    sfRenderWindow_drawSprite(game->window->w, battle->player->sprite, NULL);
    sfRenderWindow_drawSprite(game->window->w, battle->npc->sprite, NULL);
    if (battle->player->stat->speed > battle->npc->stat->speed)
        battle->start = 1;
    return (-1);
}
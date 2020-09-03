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

battle_t *reset_battle(battle_t *battle)
{
    battle->shot = 0;
    battle->reaction = -1;
    battle->slow_mo = 0;
    battle->frame = 0;
    battle->dodge = -1;
    battle->side = -1;
    battle->attack_type = 0;
    battle->too_early = 0;
    battle->player->rect.top = 0;
    battle->player->rect.left = 0;
    sfSprite_setTextureRect(battle->player->sprite, battle->player->rect);
    sfSprite_setPosition(battle->player->sprite, (sfVector2f) {200, 540});
    sfSprite_setPosition(battle->npc->sprite, (sfVector2f) {1720, 540});
    return (battle);
}

void update_characters(battle_t *battle, game_t *game)
{
    if (battle->side == 1 && battle->shot == 1) {
        npc_dodge(battle, game);
        update_battle_player(battle, game);
    }
    if (battle->side != 1 && battle->shot == 1) {
        battle = player_dodge(battle, game);
        update_battle_npc(battle, game);
    }
    if (battle->shot == 0)
        battle = npc_shot(battle);
    if (battle->shot == 1)
        display_incantation(battle, game);
}

void update_cds(battle_t *battle, game_t *game)
{
    for (int i = 0; i < 3; i++) {
        if (battle->player_cds[i] > 0)
            battle->player_cds[i]--;
        if (battle->npc_cds[i] > 0)
            battle->npc_cds[i]--;
    }
    if (battle->npc->stat->stamina < battle->npc->stat->max_stamina &&
        battle->reaction == -1)
        battle->npc->stat->stamina += battle->npc->stat->regen_stamina;
    if (battle->player->stat->stamina < battle->player->stat->max_stamina &&
        battle->reaction == -1)
        battle->player->stat->stamina += battle->player->stat->regen_stamina;
}

battle_t *update_battle(battle_t *battle, game_t *game)
{
    update_characters(battle, game);
    sfRenderWindow_drawSprite(game->window->w, battle->player->sprite, NULL);
    sfRenderWindow_drawSprite(game->window->w, battle->npc->sprite, NULL);
    if (battle->shot == 1 && battle->reaction > 0)
        display_anim(battle, game);
    update_cds(battle, game);
    display_fight_cd(battle, game);
    return (battle);
}

int fight(battle_t *battle, game_t *game)
{
    if (battle->player->stat->hp <= 0) {
        player_dead(battle, game);
        game->manage_index = 7;
        return (0);
    }
    if (battle->npc->stat->hp <= 0) {
        enemy_dead(battle, game);
        if (game->player->numberquests == 4)
            game->manage_index = 8;
        return (1);
    }
    if (battle->start == 0)
        return (check_if_battle_start(battle, game));
    battle->frame++;
    battle->player_speed++;
    battle->npc_speed++;
    battle = update_battle(battle, game);
    return (0);
}
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
#include "my.h"

void player_dodge_too_early(battle_t *battle, game_t *game)
{
    if (battle->frame < (float) (((float)
    battle->npc->stat->weapon.nb_frame_dodges[battle->attack_type] / 2) *
    battle->player->stat->dodge) / 100 && battle->shot == 1 &&
    battle->dodge != -1)
        battle->too_early = 1;
    if (battle->shot == 1 && battle->slow_mo == 1 &&
    battle->reaction <= (float) ((battle->npc->stat->weapon.nb_frame_dodges
    [battle->attack_type]) * battle->player->stat->dodge) / 100 &&
    battle->reaction > 0 && battle->dodge != battle->attack_type &&
    battle->dodge != -1)
        battle->too_early = 1;
    if (battle->shot == 1 && battle->slow_mo == 1 && battle->reaction <=
    (float) ((battle->npc->stat->weapon.nb_frame_dodges[battle->attack_type]) *
    battle->player->stat->dodge) / 100 && battle->reaction > 0 && battle->dodge
    == battle->attack_type && battle->too_early == 0) {
        sfSprite_setPosition(battle->player->sprite, (sfVector2f) {200, 240});
        battle->too_early = -1;
    }
}

void player_nice_dodge(battle_t *battle, game_t *game)
{
    int crit = 1;

    if (rand() % 100 < battle->npc->stat->crit)
        crit = 2;
    if (battle->too_early != -1)
        battle->too_early = 1;
    if (battle->too_early == 1) {
        sfRenderWindow_clear(game->window->w,
        sfColor_fromRGB(255, 30, 30));
        battle->player->stat->hp -= ((battle->npc->stat->weapon.damage *
        ((float)battle->npc->stat->weapon.nb_frame_dodges
        [battle->attack_type] / 100)) * crit);
    }
    battle = reset_battle(battle);
}

battle_t *player_dodge(battle_t *battle, game_t *game)
{
    player_dodge_too_early(battle, game);
    if (battle->reaction > (float) (battle->npc->stat->weapon.nb_frame_dodges
    [battle->attack_type] * battle->player->stat->dodge) / 100 &&
    battle->shot == 1)
        player_nice_dodge(battle, game);
    return (battle);
}

void update_battle_player(battle_t *battle, game_t *game)
{
    if (battle->frame == (float) ((float)
        battle->player->stat->weapon.nb_frame_dodges[battle->attack_type] / 2)
        && battle->shot == 1) {
        battle->slow_mo = 1;
        battle->reaction = 1;
    }
    if (battle->frame >= (float) (
        (float)battle->player->stat->weapon.nb_frame_dodges
        [battle->attack_type] / 2) && battle->shot == 1) {
        battle->reaction++;
        sfRenderWindow_drawRectangleShape(game->window->w,
        battle->total_time, NULL);
        sfRenderWindow_drawRectangleShape(game->window->w,
        battle->current_time, NULL);
        sfRectangleShape_setSize(battle->current_time,
        (sfVector2f) {battle->reaction, 30});
    }
}
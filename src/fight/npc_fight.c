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

void check_npc_dodge(battle_t *battle, game_t *game)
{
    int crit = 1;

    if (battle->reaction >= (float)
        (battle->player->stat->weapon.nb_frame_dodges[battle->attack_type] *
        battle->npc->stat->dodge) / 100) {
        if (rand() % 100 < battle->player->stat->crit)
            crit = 2;
        if (battle->too_early != -1)
            battle->too_early = 1;
        if (battle->too_early == 1) {
            sfRenderWindow_clear(game->window->w, sfColor_fromRGB(255, 30,
            30));
            battle->npc->stat->hp -= ((battle->player->stat->weapon.damage *
            ((float)battle->player->stat->weapon.nb_frame_dodges
            [battle->attack_type] / 100)) * crit);
        }
        battle = reset_battle(battle);
    }
}

battle_t *npc_dodge(battle_t *battle, game_t *game)
{
    int dodge = rand() % 5000;
    int dodged = 0;

    if (dodge < battle->npc->stat->dodge_accurancy)
        dodged = 1;
    if (battle->shot == 1 && battle->frame >= (float) (((float)
        battle->player->stat->weapon.nb_frame_dodges[battle->attack_type] / 3)
        * battle->npc->stat->dodge) / 100 && dodged == 1) {
        if (battle->reaction < 0) {
            battle->too_early = 1;
        } else if (battle->too_early == 0) {
            sfSprite_setPosition(battle->npc->sprite, (sfVector2f){1780, 240});
            battle->too_early = -1;
        }

    }
    check_npc_dodge(battle, game);
    return (battle);
}

void update_battle_npc(battle_t *battle, game_t *game)
{
    if (battle->frame == (float)battle->player->stat->weapon.nb_frame_dodges
        [battle->attack_type] / 2 && battle->shot == 1) {
        battle->slow_mo = 1;
        battle->reaction = 1;
    }
    if (battle->frame >= battle->player->stat->weapon.nb_frame_dodges
        [battle->attack_type] / 2 && battle->shot == 1) {
        battle->reaction++;
        sfRenderWindow_drawRectangleShape(game->window->w,
        battle->total_time, NULL);
        sfRenderWindow_drawRectangleShape(game->window->w,
        battle->current_time, NULL);
        sfRectangleShape_setSize(battle->current_time,
        (sfVector2f) {battle->reaction, 30});
    }
}
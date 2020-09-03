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

void display_fight_cd(battle_t *battle, game_t *game)
{
    for (int i = 0; i < 3; i++) {
        sfRectangleShape_setSize(battle->player_cds_rect[i], (sfVector2f)
            {(float) battle->player_cds[i] /
            battle->player->stat->weapon.cds[i] * 100, 100});
        sfRenderWindow_drawRectangleShape(game->window->w,
            battle->player_cds_rect[i], NULL);
    }
}

void display_anim(battle_t *battle, game_t *game)
{
    if (battle->side == 1) {
        sfSprite_setTextureRect(battle->sprite_effect,
        battle->player->stat->weapon.anim_rects[battle->attack_type]);
        battle->player->stat->weapon.anim_rects[battle->attack_type].left =
        (battle->player->stat->weapon.anim_rects[battle->attack_type].width *
        (battle->frame % battle->player->stat->weapon.nb_frame_anim
        [battle->attack_type]));
    }
    if (battle->side != 1) {
        sfSprite_setTextureRect(battle->sprite_effect,
        battle->npc->stat->weapon.anim_rects[battle->attack_type]);
        battle->npc->stat->weapon.anim_rects[battle->attack_type].left =
        (battle->npc->stat->weapon.anim_rects[battle->attack_type].width *
        (battle->frame % battle->npc->stat->weapon.nb_frame_anim
        [battle->attack_type]));
    }
    sfRenderWindow_drawSprite(game->window->w, battle->sprite_effect, NULL);
}

void display_incantation(battle_t *battle, game_t *game)
{
    if (battle->side == 1) {
        sfSprite_setTextureRect(battle->sprite_incantation,
            battle->player->stat->weapon.anim_rects[3]);
        battle->player->stat->weapon.anim_rects[3].left =
        (battle->player->stat->weapon.anim_rects[3].width *
            (battle->frame % battle->player->stat->weapon.nb_frame_anim[3]));
    }
    if (battle->side != 1) {
        sfSprite_setTextureRect(battle->sprite_incantation,
        battle->npc->stat->weapon.anim_rects[3]);
        battle->npc->stat->weapon.anim_rects[3].left =
        (battle->npc->stat->weapon.anim_rects[3].width *
        (battle->frame % battle->npc->stat->weapon.nb_frame_anim[3]));
    }
    sfRenderWindow_drawSprite(game->window->w, battle->sprite_incantation,
    NULL);
}
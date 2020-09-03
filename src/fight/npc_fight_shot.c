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

int npc_check_shot(battle_t *battle)
{
    int shot = 0;
    int attack = rand() % 3;

    for (int i = 0; i < 3; i++) {
        if (battle->npc_cds[i] <= 0 && attack == i) {
            battle = reset_battle(battle);
            battle->side = 2;
            battle->shot = 1;
            battle->attack_type = i;
            shot = 1;
            battle->npc_cds[i] += battle->npc->stat->weapon.cds[1];
            return (1);
        }
    }
    return (0);
}

void npc_shot_sprite(battle_t *battle)
{
    sfVector2f pos;

    sfSprite_setTexture(battle->sprite_effect,
    battle->npc->stat->weapon.texture_fight[battle->attack_type], sfTrue);
    sfSprite_setTextureRect(battle->sprite_effect,
    battle->npc->stat->weapon.anim_rects[battle->attack_type]);
    sfSprite_setScale(battle->sprite_effect, (sfVector2f) {-1, 1});
    pos = (sfVector2f) {250 + (battle->npc->stat->weapon.anim_rects
    [battle->attack_type].width / 2), 540 -
    (battle->npc->stat->weapon.anim_rects[battle->attack_type].height / 2)};
    sfSprite_setPosition(battle->sprite_effect, pos);
    sfSprite_setTexture(battle->sprite_incantation,
    battle->npc->stat->weapon.texture_fight[3], sfTrue);
    sfSprite_setTextureRect(battle->sprite_incantation,
    battle->npc->stat->weapon.anim_rects[3]);
    sfSprite_setPosition(battle->sprite_incantation, (sfVector2f) {1750 -
    (battle->npc->stat->weapon.anim_rects[3].width / 2), 540 -
    (battle->npc->stat->weapon.anim_rects[3].height / 2)});
}

void npc_shot_anim(battle_t *battle)
{
    sfColor color;
    float val;

    battle->npc_speed = 0;
    battle->npc->stat->stamina -= battle->npc->stat->weapon.stamina;
    val = (float) (battle->npc->stat->weapon.nb_frame_dodges
    [battle->attack_type] * battle->player->stat->dodge) / 100;
    battle->total_time = make_rectangle((sfVector2f)
    {1920 / 2 - val / 2, 1080 / 2}, (sfVector2f) {val, 30}, sfBlack);
    if (battle->attack_type == 0)
        color = sfMagenta;
    if (battle->attack_type == 1)
        color = sfWhite;
    if (battle->attack_type == 2)
        color = sfCyan;
    battle->current_time = make_rectangle((sfVector2f)
    {1920 / 2 - val / 2, 1080 / 2}, (sfVector2f) {0, 30}, color);
    npc_shot_sprite(battle);
}

battle_t *npc_shot(battle_t *battle)
{
    int shot = 0;

    if (battle->npc->stat->stamina < battle->npc->stat->weapon.stamina)
        return (battle);
    if (battle->npc_speed < battle->npc->stat->speed)
        return (battle);
    shot = npc_check_shot(battle);
    if (shot == 1)
        npc_shot_anim(battle);
    return (battle);
}
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

int can_player_shot(battle_t *battle, game_t *game, float val)
{
    if (battle->player_speed < battle->player->stat->speed &&
    battle->start == 1)
        return (0);
    if (battle->attack_type == 0 && battle->player_cds[0] > 0)
        return (0);
    if (battle->attack_type == 1 && battle->player_cds[1] > 0)
        return (0);
    if (battle->attack_type == 2 && battle->player_cds[2] > 0)
        return (0);
    battle->side = 1;
    battle->shot = 1;
    battle->start = 1;
    battle->frame = 0;
    battle->total_time = make_rectangle((sfVector2f)
    {1920 / 2 - val / 2, 1080 / 2}, (sfVector2f) {val, 30}, sfBlack);
    return (1);
}

sfColor get_attack(battle_t *battle, game_t *game)
{
    sfColor colors[] = {sfRed, sfGreen, sfBlue};

    for (int i = 0; i < 3; i++) {
        if (battle->attack_type == i) {
            battle->player_cds[i] += battle->player->stat->weapon.cds[i];
            return (colors[i]);
        }
    }
}

void player_shot_sprite(battle_t *battle, game_t *game, float val)
{
    sfVector2f pos;
    sfSprite_setScale(battle->sprite_effect, (sfVector2f) {1, 1});
    pos = (sfVector2f) {1100 + (battle->player->stat->weapon.anim_rects
    [battle->attack_type].width / 2), 540 -
    (battle->player->stat->weapon.anim_rects[battle->attack_type].height / 2)};
    sfSprite_setPosition(battle->sprite_effect, pos);
    sfSprite_setTexture(battle->sprite_incantation,
    battle->player->stat->weapon.texture_fight[3], sfTrue);
    sfSprite_setTextureRect(battle->sprite_incantation,
    battle->player->stat->weapon.anim_rects[3]);
    sfSprite_setPosition(battle->sprite_incantation, (sfVector2f)
    {100 - (battle->player->stat->weapon.anim_rects[3].width / 2), 540 -
    (battle->player->stat->weapon.anim_rects[3].height / 2)});
}

void player_shot(battle_t *battle, game_t *game)
{
    float val = (float) (battle->player->stat->weapon.nb_frame_dodges
    [battle->attack_type] * battle->npc->stat->dodge) / 100;
    sfColor color;

    if (can_player_shot(battle, game, val) == 0)
        return;
    color = get_attack(battle, game);
    battle->player->stat->stamina -= battle->player->stat->weapon.stamina;
    battle->current_time = make_rectangle((sfVector2f)
    {1920 / 2 - val / 2, 1080 / 2}, (sfVector2f) {0, 30}, color);
    battle->player_speed = 0;
    sfSprite_setTexture(battle->sprite_effect,
    battle->player->stat->weapon.texture_fight[battle->attack_type], sfTrue);
    sfSprite_setTextureRect(battle->sprite_effect,
    battle->player->stat->weapon.anim_rects[battle->attack_type]);
    player_shot_sprite(battle, game, val);
}
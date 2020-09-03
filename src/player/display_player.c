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

void update_player_rect(player_t *player)
{
    if (player->frame % 15 == 0)
        player->anim++;
    if (player->dir.x == 0 && player->dir.y == 0)
        player->anim = 0;
    if (abs(player->dir.x) < abs(player->dir.y)) {
        if (player->dir.y < 0)
            player->rect.top = 180;
        else
            player->rect.top = 0;
    } else if (abs(player->dir.x) > abs(player->dir.y))
        if (player->dir.x < 0)
            player->rect.top = 60;
        else
            player->rect.top = 120;
}

void display_player(player_t *player, sfRenderWindow *window)
{
    sfVector2f pos = (sfVector2f) {player->pos.x - (30 * player->size.x),
        player->pos.y - (30 * player->size.y)};

    if (player->stat->hp <= 0)
        return;
    update_player_rect(player);
    player->rect.left = (player->anim % 3) * 60;
    sfSprite_setTextureRect(player->sprite, player->rect);
    sfSprite_setPosition(player->sprite, pos);
    sfSprite_setScale(player->sprite, player->size);
    sfRenderWindow_drawSprite(window, player->sprite, NULL);
}
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

void display_text(npc_t *npc, game_t *game)
{
    sfIntRect rect_pos;

    if (npc->text == -1) {
        npc->text_cursor = 0;
        npc->start_dialog = 0;
        return;
    }
    if (npc->start_dialog == 1 && npc->text_cursor < 200) {
        rect_pos = get_rect_pos(game, npc);
        sfSprite_setTextureRect(game->talk_sprite, rect_pos);
        sfSprite_setPosition(game->talk_sprite, (sfVector2f)
        {npc->pos.x, npc->pos.y - 100});
        sfRenderWindow_drawSprite(game->window->w, game->talk_sprite, sfFalse);
    }
    if (npc->frame % 5 == 0)
        npc->text_cursor++;
    if (npc->text_cursor >= 200) {
        npc->start_dialog = 0;
        npc->text_cursor = 0;
    }
}

npc_t get_next_destination(npc_t npc)
{
    if (npc.side == 0 && npc.move_index < npc.nb_movements) {
        npc.move_index++;
        npc.destination = npc.movements[npc.move_index];
    }
    if (npc.side == 1 && npc.move_index > 0) {
        npc.move_index--;
        npc.destination = npc.movements[npc.move_index];
    }
    if (npc.move_index == npc.nb_movements - 1 ||
        npc.move_index == 0) {
        npc.side ^= 1;
    }
    return (npc);
}

npc_t npc_walk(npc_t npc)
{
    sfVector2f dir;
    float dist_f;

    if (dist(npc.pos.x, npc.pos.y, npc.destination.x,
        npc.destination.y) < npc.walk_speed)
        npc = get_next_destination(npc);
    dist_f = dist(npc.pos.x, npc.pos.y, npc.destination.x, npc.destination.y);
    dir.x = (npc.destination.x - npc.pos.x) / dist_f * npc.walk_speed;
    dir.y = (npc.destination.y - npc.pos.y) / dist_f * npc.walk_speed;
    npc.pos.x += dir.x;
    npc.pos.y += dir.y;
    sfSprite_setPosition(npc.sprite, npc.pos);
    return (npc);
}

npc_t render_npc(npc_t npc, game_t *game)
{
    if (npc.frame % 20 == 0) {
        npc.anim++;
        npc.rect.left = (npc.anim % npc.frame_count) * 60;
        sfSprite_setTextureRect(npc.sprite, npc.rect);
    }
    display_text(&npc, game);
    if (npc.start_dialog == 0 && npc.nb_movements > 0)
        npc = npc_walk(npc);
    sfRenderWindow_drawSprite(game->window->w, npc.sprite, NULL);
    return (npc);
}

void display_npc(npc_t *npcs, game_t *game)
{
    for (int i = 0; i < game->nb_npc; i++) {
        if (npcs[i].stat != NULL && npcs[i].stat->hp <= 0)
            npcs[i].render_state = 0;
        if (npcs[i].render_state != 0) {
            npcs[i] = render_npc(npcs[i], game);
        }
    }
}
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
#include <SFML/Audio/Music.h>
#include "functions.h"
#include "my.h"

void display_shop(game_t *game, inventory_t *inventory)
{
    if (game->player->npc_interact_index != -1 && game->player->in_shop) {
        for (int j = 0; j <
            game->npcs[game->player->npc_interact_index].nb_items; j++)
            sfRenderWindow_drawSprite(game->window->w, game->items[game->npcs
            [game->player->npc_interact_index].items[j]].sprite, NULL);
        for (int j = 0; j <
            game->npcs[game->player->npc_interact_index].nb_weapons; j++) {
            sfVector2f pos = sfSprite_getPosition(game->weapons[game->npcs
            [game->player->npc_interact_index].weapons[j]].sprite);
            sfRenderWindow_drawSprite(game->window->w, game->weapons[game->npcs
            [game->player->npc_interact_index].weapons[j]].sprite, NULL);
        }
        sfRenderWindow_drawSprite(game->window->w, game->player->shop_sprite,
        NULL);
        sfSprite_setPosition(game->player->sprite, (sfVector2f) {245, 100});
    }
}

void display_inventory(game_t *game, inventory_t *inventory)
{
    sfRenderWindow_drawSprite(game->window->w, inventory->bg_sprite, NULL);
    sfSprite_setPosition(game->player->sprite, (sfVector2f) {810, 100});
    sfSprite_setScale(game->player->sprite, (sfVector2f) {5, 5});
    display_shop(game, inventory);
    sfRenderWindow_drawSprite(game->window->w, inventory->sprite, NULL);
    for (int i = 0; i < 17; i++)
        if (inventory->items[i].name)
            sfRenderWindow_drawSprite(game->window->w,
                inventory->items[i].sprite, NULL);
        else if (inventory->weapons[i].name)
            sfRenderWindow_drawSprite(game->window->w,
                inventory->weapons[i].sprite, NULL);
    game->player->rect.top = 0;
    game->player->rect.left = 0;
    sfSprite_setTextureRect(game->player->sprite, game->player->rect);
    sfRenderWindow_drawSprite(game->window->w, game->player->sprite, NULL);
}

void display_effects(game_t *game)
{
    for (int i = 0; game->effects != NULL && game->effect_index != NULL &&
        i < game->nb_effect; i++)
        if (game->effect_index[i] >= 0)
            do_effect(game->effects[game->effect_index[i]], game->window->w);
}

void display_game(game_t *game)
{
    if (game->frame % 2 == 0) {
        update_player(game->player, game);
        game->player->frame++;
        for (int i = 0; game->npcs != NULL && i < game->nb_npc; i++)
            game->npcs[i].frame++;
        display_maps(game);
        if (game->high_or_low == 1)
            display_effects(game);
    }
    if (game->player->inventory_open == 1)
        display_inventory(game, game->player->inventory);
}

void game(game_t *game)
{
    if (game->w_music % 2 != 0) {
            sfMusic_play(game->music->game);
            game->w_music++;
    }
    sfTime time = sfClock_getElapsedTime(game->clock);
    int sec = sfTime_asMilliseconds(time);
    sfTime fps_time = sfClock_restart(game->fps_clock);
    int fps_sec = sfTime_asMilliseconds(fps_time);

    if (game->frame == 60)
        sfClock_restart(game->clock);
    if (sec % (1600000) == 0) {
        game->frame++;
    }
    if (game->player->in_fight == 0)
        display_game(game);
    if (game->player->in_fight == 1 && game->frame % 2 == 0)
        fight(game->battle, game);
}
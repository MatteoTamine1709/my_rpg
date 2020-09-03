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

void update_map(map_t *map, image_t **images, sfVector2i pos, int val)
{
    for (int k = pos.x + 1; k < pos.x + images[val]->size.x && k < 16; k++) {
        map->map[k][pos.y] = -1;
        for (int l = pos.y + 1; l < pos.y + images[val]->size.y && l < 9; l++)
            map->map[k][l] = -1;
    }
    for (int k = pos.y + 1; k < pos.y + images[val]->size.y && k < 9; k++)
        map->map[pos.x][k] = -1;
}

void display_map_sprite(map_t *map, image_t **images,
    game_t *game, sfVector2i pos)
{
    int val = map->map[pos.x][pos.y];

    if (val < game->nb_map_image && val >= 0 && images != NULL) {
        sfSprite_setPosition(images[val]->sprite, (sfVector2f) {pos.x * 120,
            pos.y * 120});
        sfRenderWindow_drawSprite(game->window->w, images[val]->sprite, NULL);
        update_map(map, images, pos, val);
    }
}

void display_map(map_t *map, image_t **images, game_t *game)
{
    int val = 0;

    for (int i = 0; i < 16; i++)
        for (int j = 0; j < 9; j++)
            display_map_sprite(map, images, game, (sfVector2i) {i, j});
}

void display_maps(game_t *game)
{
    if (game->bg_map != NULL)
        display_map(game->bg_map, game->map_images, game);
    if (game->mg_map != NULL)
        display_map(game->mg_map, game->map_images, game);
    if (game->npcs != NULL)
        display_npc(game->npcs, game);
    if (game->player->in_fight == 0)
        display_player(game->player, game->window->w);
    if (game->fg_map != NULL)
        display_map(game->fg_map, game->map_images, game);
    if (game->props != NULL && game->high_or_low == 1)
        display_props(game->props, game);
    if (game->lights != NULL && game->high_or_low == 1)
        display_lights(game->lights, game);
}
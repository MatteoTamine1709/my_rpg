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
#include "my.h"

void check_tile_bg(game_t *game, sfVector2i ij, int *val, sfVector2i *size)
{
    sfVector2i pos = (sfVector2i) {(int) (game->player->pos.x / 120),
        (int) ((game->player->pos.y + (30 * game->player->size.y)) / 120)};
    int index = game->bg_map->map[pos.x -
        (pos.x - ij.y)][pos.y - (pos.y - ij.x)];
    if (index != -1) {
        if (game->map_images[index]->size.x > pos.x - ij.y &&
            game->map_images[index]->size.y > pos.y - ij.x) {
            *val = index;
            *size = (sfVector2i) {(pos.x - ij.y), (pos.y - ij.x)};
        }
    }
}

void check_other_tile_bg(player_t *player, game_t *game,
    int *val, sfVector2i *size)
{
    sfVector2i pos;
    int index;

    pos.x = (int) (player->pos.x / 120);
    pos.y = (int) ((player->pos.y + (30 * game->player->size.y)) / 120);
    for (int i = pos.y; i >= 0; i--)
        for (int j = pos.x; j >= 0; j--)
            check_tile_bg(game, (sfVector2i){i, j}, val, size);
}

int check_pixel_bg(game_t *game, player_t *player, int val, sfVector2i size)
{
    sfImage *image = NULL;

    if (val > -1 && val < game->nb_map_image)
        image = game->map_images[val]->hitbox;
    if (val != -1 && image != NULL &&
        sfImage_getPixel(image,
        ((int)player->pos.x % 120 + (120 * size.x)),
        ((int)(player->pos.y + (30 * game->player->size.y)) % 120 +
            (120 * size.y))).r == 0) {
        player->pos.x -= player->dir.x;
        player->pos.y -= player->dir.y;
        return (1);
    }
    return (0);
}

int hitbox_bg(game_t *game, player_t *player)
{
    sfVector2i size = (sfVector2i) {0, 0};
    int val;

    if (game->bg_map == NULL)
        return (0);
    val = game->bg_map->map[(int)(player->pos.x / 120)]
        [(int)((player->pos.y + (30 * game->player->size.y)) / 120)];
    if (val == -1)
        check_other_tile_bg(player, game, &val, &size);
    return (check_pixel_bg(game, player, val, size));
}
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

void check_tile_fg(game_t *game, sfVector2i ij, int *val, sfVector3f *size)
{
    sfVector2i pos = (sfVector2i) {(int) (game->player->pos.x / 120),
        (int) ((game->player->pos.y + (30 * size->z)) / 120)};
    int index = game->fg_map->map[pos.x -
        (pos.x - ij.y)][pos.y - (pos.y - ij.x)];
    if (index != -1) {
        if (game->map_images[index]->size.x > pos.x - ij.y &&
            game->map_images[index]->size.y > pos.y - ij.x) {
            *val = index;
            *size = (sfVector3f) {(pos.x - ij.y), (pos.y - ij.x)};
        }
    }
}

void check_other_tile_fg(player_t *player, game_t *game,
    int *val, sfVector3f *size)
{
    sfVector3f pos;
    int index = 0;

    pos.x = (int) (player->pos.x / 120);
    pos.y = (int) ((player->pos.y + (30 * size->z)) / 120);
    for (int i = pos.y; i > 0; i--)
        for (int j = pos.x; j > 0; j--)
            check_tile_fg(game, (sfVector2i){i, j}, val, size);
}

int check_pixel_fg(game_t *game, player_t *player, int val, sfVector3f size)
{
    sfImage *image = NULL;

    if (val > -1 && val < game->nb_map_image)
        image = game->map_images[val]->hitbox;
    if (val != -1 && image != NULL &&
        sfImage_getPixel(image,
        ((int)player->pos.x % 120 + (120 * size.x)),
        ((int)(player->pos.y + (30 * size.z)) % 120 + (120 * size.y))).r ==
        0) {
        player->pos.x -= player->dir.x;
        player->pos.y -= player->dir.y;
        return (1);
    }
    return (0);
}

int hitbox_fg(game_t *game, player_t *player)
{
    sfVector3f size = (sfVector3f) {0, 0, -1};
    int val = 0;

    if (game->fg_map == NULL)
        return (0);
    val = game->fg_map->map[(int)(player->pos.x / 120)]
        [(int)((player->pos.y - 30) / 120)];
    if (val == -1)
        check_other_tile_fg(player, game, &val, &size);
    if (check_pixel_fg(game, player, val, size))
        return (1);
    size.z = 1;
    val = game->fg_map->map[(int)(player->pos.x / 120)]
        [(int)((player->pos.y + 30) / 120)];
    if (val == -1)
        check_other_tile_fg(player, game, &val, &size);
    return (check_pixel_fg(game, player, val, size));
}
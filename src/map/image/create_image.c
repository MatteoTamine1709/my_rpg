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

image_t *init_image(sfVector2i size, char *texture_path)
{
    image_t *image = my_malloc(sizeof(image_t));
    char *texture = my_strcat(texture_path, ".png");
    char *texture_hitbox = my_strcat(texture_path, "_hitbox.jpg");
    int fd;

    image->size = size;
    image->sprite = sfSprite_create();
    image->texture = NULL;
    image->hitbox = NULL;
    image->rect = (sfIntRect) {0, 0, 120 * size.x, 120 * size.y};
    image->texture = sfTexture_createFromFile(texture,
        &image->rect);
    sfSprite_setTexture(image->sprite, image->texture, sfFalse);
    sfSprite_setPosition(image->sprite, (sfVector2f) {0, 0});
    if ((fd = open(texture_hitbox, O_RDONLY)) != -1) {
        image->hitbox = sfImage_createFromFile(texture_hitbox);
        close(fd);
    }
    return (image);
}

image_t **get_image(int size, char *buff, game_t *game)
{
    int index;
    sfVector2i size_tile;
    char *texture_path;

    for (int i = 0; i < size; i += get_size_n(buff, i) + 1) {
        index = my_atoi_dot(buff, i);
        i += get_size_dot(buff, i) + 1;
        size_tile.x = my_atoi_dot(buff, i);
        i += get_size_dot(buff, i) + 1;
        size_tile.y = my_atoi_dot(buff, i);
        i += get_size_dot(buff, i) + 1;
        texture_path = get_string_dot(buff, i);
        game->map_images[index] = init_image(size_tile, texture_path);
    }
    return (game->map_images);
}

image_t **create_images(game_t *game)
{
    int fd = open("saves/save1/image_pair", O_RDONLY);
    char buff[35000];
    int nb_line = 0;
    int size;

    if (fd == -1)
        return (NULL);
    size = read(fd, buff, sizeof(char) * 35000);
    buff[size] = '\0';
    for (int i = 0; buff[i]; i++)
        if (buff[i] == '\n')
            nb_line++;
    game->nb_map_image = nb_line + 1;
    game->map_images = my_malloc(sizeof(image_t) * game->nb_map_image);
    game->map_images = get_image(size, buff, game);
    return (game->map_images);
}
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

item_t *load_item_info(char *buff, int size, item_t *items, int nb_item)
{
    int c_item = 0;
    int index = 0;

    item_t (*set_item_var[])(item_t, int, char *) = {item_name, item_price,
        item_texture, item_type, item_level_power, item_hp, item_speed,
        item_stamina, item_agility, item_crit};
    for (int i = get_size_n(buff, 0) + 1; i < size;
        i += (get_size_n(buff, i) + 1)) {
        if (index < 10)
            items[c_item] = (*set_item_var[index])(items[c_item], i, buff);
        index++;
        if (next_info(buff[i], (int *[3]) {&c_item, &nb_item, &index}) == 1)
            return (items);
    }
    return (items);
}

item_t fill_item(void)
{
    item_t item;

    item.price = -1;
    item.type = -1;
    item.hp = 0;
    item.speed = 0;
    item.stamina = 0;
    item.dodge = 0;
    item.crit = 0;
    item.name = NULL;
    item.level_power = -1;
    return (item);
}

item_t *set_item_design(item_t *items, int nb_item)
{
    for (int i = 0; i < nb_item; i++) {
        items[i].sprite = sfSprite_create();
        items[i].texture = sfTexture_createFromFile(items[i].texture_path,
            NULL);
        sfSprite_setTexture(items[i].sprite, items[i].texture, sfFalse);
    }
    return (items);
}

item_t *load_items(char *filepath, game_t *game)
{
    int fd = open(filepath, O_RDONLY);
    char buff[2000];
    int size;
    int nb_item = 0;
    item_t *items = NULL;
    game->nb_item = 0;

    if (fd == -1)
        return NULL;
    size = read(fd, buff, sizeof(char) * 2000);
    buff[size] = '\0';
    nb_item = my_atoi_n(buff, 0);
    items = my_malloc(sizeof(item_t) * nb_item);
    for (int i = 0; i < nb_item; i++)
        items[i] = fill_item();
    items = load_item_info(buff, size, items, nb_item);
    items = set_item_design(items, nb_item);
    game->nb_item = nb_item;
    return (items);
}
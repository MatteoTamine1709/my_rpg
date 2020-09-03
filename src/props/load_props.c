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

prop_t *load_prop_info(char *buff, int size, prop_t *props, int nb_props)
{
    int c_prop = 0;
    int index = 0;

    prop_t(*set_prop_var[])(prop_t,
    int, char *) = {
        prop_pos_x, prop_pos_y, prop_hitbox_x, prop_hitbox_y, prop_texture
    };
    for (int i = get_size_n(buff, 0) + 1;
        i < size; i += (get_size_n(buff, i) + 1)) {
        if (index < 5)
            props[c_prop] = (*set_prop_var[index])(props[c_prop], i, buff);
        index++;
        if (next_info(buff[i], (int *[3]) {&c_prop, &nb_props, &index}) == 1)
            return (props);
    }
    return (props);
}

prop_t fill_prop(void)
{
    prop_t prop;

    prop.pos = (sfVector2f){-1, -1};
    prop.hitbox_size = (sfVector2f){-1, -1};
    prop.texture = NULL;
    prop.sprite = NULL;
    return (prop);
}

prop_t *set_prop_design(prop_t *props, int nb_props)
{
    for (int i = 0; i < nb_props; i++) {
        props[i].sprite = sfSprite_create();
        props[i].texture = sfTexture_createFromFile(props[i].texture_path,
            NULL);
        sfSprite_setTexture(props[i].sprite, props[i].texture, sfFalse);
        sfSprite_setPosition(props[i].sprite, props[i].pos);
    }
    return (props);
}

prop_t *load_props(char *filepath, game_t *game)
{
    int fd = open(filepath, O_RDONLY);
    char buff[2000];
    int size = 0;
    prop_t *props;
    game->nb_props = 0;

    if (fd == -1)
        return (NULL);
    size = read(fd, buff, sizeof(char) * 2000);
    if (size < 2)
        return (NULL);
    buff[size] = '\0';
    game->nb_props = my_atoi_n(buff, 0);
    props = my_malloc(sizeof(prop_t) * game->nb_props);
    for (int i = 0; i < game->nb_props; i++)
        props[i] = fill_prop();
    props = load_prop_info(buff, size, props, game->nb_props);
    props = set_prop_design(props, game->nb_props);
    return (props);
}